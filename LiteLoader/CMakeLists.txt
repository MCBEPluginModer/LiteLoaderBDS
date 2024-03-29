cmake_minimum_required(VERSION 3.21)
project(LiteLoader)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release) # Always uses Release mode to build BDS plugin for ABI Compatibility

file(
    GLOB_RECURSE SRC_FILES
    ${PROJECT_SOURCE_DIR}/third-party/include/*.h
    ${PROJECT_SOURCE_DIR}/third-party/include/*.hpp
    ${PROJECT_SOURCE_DIR}/include/*.h
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.h
    ${PROJECT_SOURCE_DIR}/src/*.rc
)

# third-party source files
file(GLOB_RECURSE THIRD_PARTY_SRC_FILES ${PROJECT_SOURCE_DIR}/third-party/src/*)

add_library(LiteLoader SHARED ${SRC_FILES} ${THIRD_PARTY_SRC_FILES} "include/llapi/mc/CommandParameter.h")

# Replace Compile Flag /EHsc to /EHa
string(REPLACE "/EHsc" "/EHa" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

target_compile_options(
    LiteLoader
    PRIVATE /permissive- /MD /MP /analyze:external- /GS /GL /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /sdl /Zc:inline /fp:precise /errorReport:prompt /WX- /Zc:forScope /Gd /Oi /FC /nologo /Ot /diagnostics:column /utf-8
)

target_compile_definitions(
    LiteLoader
    PRIVATE -DUNICODE -DNDEBUG -DLITELOADER_EXPORTS -DWIN32_LEAN_AND_MEAN -DCPPHTTPLIB_OPENSSL_SUPPORT -D_CRT_SECURE_NO_WARNINGS -D_WINDOWS -D_USRDLL -D_AMD64_ -DNOMINMAX
)

# use delayload to import BDS APIs manually(bedrock_server.dll does not need to exist)
target_link_options(
    LiteLoader
    PRIVATE /MANIFEST /LTCG /NXCOMPAT /DEBUG:FULL /DLL /MACHINE:X64 /OPT:REF /INCREMENTAL:NO /SUBSYSTEM:CONSOLE /MANIFESTUAC:NO /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1 /DELAYLOAD:bedrock_server.dll
)

target_link_libraries(
    LiteLoader
    "${PROJECT_SOURCE_DIR}/third-party/lib/leveldb/leveldb.lib"
    "${PROJECT_SOURCE_DIR}/third-party/lib/openssl/libcrypto.lib"
    "${PROJECT_SOURCE_DIR}/third-party/lib/openssl/libssl.lib"
    "${PROJECT_SOURCE_DIR}/third-party/lib/SQLiteCpp/SQLiteCpp.lib"
    "${PROJECT_SOURCE_DIR}/third-party/lib/SQLiteCpp/sqlite3.lib"
    "${PROJECT_SOURCE_DIR}/third-party/lib/mysql/mysqlclient.lib"
    "${PROJECT_SOURCE_DIR}/third-party/lib/compact_enc_det/ced.lib"
    "${PROJECT_SOURCE_DIR}/third-party/lib/dyncall/dyncall_s.lib"
    "${PROJECT_SOURCE_DIR}/third-party/lib/dyncall/dyncallback_s.lib"
    "${PROJECT_SOURCE_DIR}/third-party/lib/dyncall/dynload_s.lib"
    "${PROJECT_SOURCE_DIR}/third-party/lib/dbghelp/dbghelp.lib"

    # Please make sure that the BDS APIs ImportLibrary is at the bottom of the list to ensure proper linking.
    "${PROJECT_SOURCE_DIR}/Lib/bedrock_server_api.lib"
    "${PROJECT_SOURCE_DIR}/Lib/bedrock_server_var.lib"
    LLPreLoader
)

target_include_directories(
    LiteLoader SYSTEM
    PRIVATE ${PROJECT_SOURCE_DIR}/third-party/include
)

target_include_directories(
    LiteLoader
    PRIVATE ${PROJECT_SOURCE_DIR}/include/
    PRIVATE ${CMAKE_SOURCE_DIR}
)

add_custom_command(
    TARGET LiteLoader PRE_BUILD
    COMMAND ${CMAKE_SOURCE_DIR}/scripts/PrepareLibraries.bat ${CMAKE_SOURCE_DIR}
)

# Copy the built DLL and PDB to the output directory
add_custom_command(
    TARGET LiteLoader POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:LiteLoader> ${CMAKE_BINARY_DIR}/output/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_PDB_FILE:LiteLoader> ${CMAKE_BINARY_DIR}/pdb/
    COMMENT "Copying LiteLoader DLL and PDB to output directory"
    VERBATIM
)

# Copy the built lib to the SDK directory
add_custom_command(
    TARGET LiteLoader POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_LINKER_FILE:LiteLoader> ${CMAKE_BINARY_DIR}/sdk/lib/
    COMMENT "Copying LiteLoader Lib to SDK directory"
    VERBATIM
)

# copy target DLL and PDB to local bds dev directory
if(NOT "${BDS_LOCAL_DEV_ENVIRONMENT_DIR}" STREQUAL "")
    add_custom_command(
        TARGET LiteLoader POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:LiteLoader> ${BDS_LOCAL_DEV_ENVIRONMENT_DIR}/
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_PDB_FILE:LiteLoader> ${BDS_LOCAL_DEV_ENVIRONMENT_DIR}/plugins/LiteLoader/pdb/
        COMMENT "Copying ${PROJECT_NAME} DLL and PDB to local bds dev directory"
        VERBATIM
    )
endif()
