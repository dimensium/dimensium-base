file(
    GLOB_RECURSE
        LIBFREECRAFT_SOURCES

    *.c *.cc *.C *.cpp *.cxx
)

## configuration options

set(
    BUILD_SHARED_LIBS
        OFF
    CACHE
        BOOL
        "Decide whether to build shared libs or not"
)

if(${BUILD_SHARED_LIBS})
    add_library(
        libFreecraft SHARED
        ${LIBFREECRAFT_SOURCES}
    )
else()
    add_library(
        libFreecraft
        ${LIBFREECRAFT_SOURCES}
    )
endif()

target_include_directories(
    libFreecraft PUBLIC
        ./
)

# doesn't have a library now
# target_link_libraries(
#     libFreecraft PUBLIC
# )