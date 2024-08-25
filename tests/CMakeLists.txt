# Ignore sign warnings when expanding bandit's macros.
file(GLOB BANDIT_SOURCE_FILES *.cpp)
set_property(SOURCE ${BANDIT_SOURCE_FILES} APPEND PROPERTY COMPILE_FLAGS
    " -Wno-sign-conversion -Wno-conversion")
add_executable(unit-test ${BANDIT_SOURCE_FILES})
target_include_directories(unit-test PUBLIC ${meta_SOURCE_DIR}/../deps/bandit/)
target_link_libraries(unit-test meta-index
                                meta-classify
                                meta-regression
                                meta-stats
                                meta-parser
                                meta-features
                                meta-language-model
                                meta-succinct
                                meta-topics)
