file(
    GLOB_RECURSE
        DIMENSIUM_BASE_SOURCES

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
        dimensium_base SHARED
        ${DIMENSIUM_BASE_SOURCES}
    )
else()
    add_library(
        dimensium_base
        ${DIMENSIUM_BASE_SOURCES}
    )
endif()

target_include_directories(
    dimensium_base PUBLIC
        ./
        ../lib/
)

# doesn't have a library now
# target_link_libraries(
#     dimensium_base PUBLIC
# )