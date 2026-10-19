# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(miniccTests LANGUAGES C)

# ---- Tests ----

add_executable(minicc_test source/minicc_test.c)
target_link_libraries(minicc_test PRIVATE minicc_lib)
target_compile_features(minicc_test PRIVATE c_std_99)

add_test(NAME minicc_test COMMAND minicc_test)

# ---- End-of-file commands ----

add_folders(Test)
