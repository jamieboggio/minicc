#include "argparse/argparse.hpp"
#include "lexer.hpp"
#include <array>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

[[noreturn]]
void error_exit(const std::string msg)
{
    std::cerr << msg << '\n';
    exit(EXIT_FAILURE);
}

void run_command(const std::string& command, const std::string& fail_msg)
{
    if (std::system(command.c_str()) != 0) {
        error_exit(fail_msg);
    }
}

int main(const int argc, const char** argv)
{
    argparse::ArgumentParser program("minicc", "0.2.0");
    program.add_argument("input").help("Path to the C source file");

    auto& modes = program.add_mutually_exclusive_group();
    modes.add_argument("--lex").help("Stop after lexical analysis").flag();
    modes.add_argument("--parse").help("Stop after parsing").flag();
    modes.add_argument("--codegen").help("Stop after code generation").flag();

    try {
        program.parse_args(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cerr << program;
        return EXIT_FAILURE;
    }

    if (argc == 1) {
        std::cout << program;
        return EXIT_FAILURE;
    }

    const std::string input_filename = program.get<std::string>("input");
    const std::filesystem::path input_path{input_filename};

    if (input_path.extension() != ".c" || !std::filesystem::is_regular_file(input_filename)) {
        error_exit("Input must be an existing .c file");
    }

    std::filesystem::path preprocessed_path = input_path;
    preprocessed_path.replace_extension(".i");
    if (program.is_used("--lex")) {
        return EXIT_SUCCESS;
    }

    std::filesystem::path assembly_path = input_path;
    assembly_path.replace_extension(".s");
    if (program.is_used("--parse")) {
        return EXIT_SUCCESS;
    }

    if (program.is_used("--codegen")) {
        return EXIT_SUCCESS;
    }
    std::filesystem::path exe_out_path = input_path;
    exe_out_path.replace_extension("");
    return EXIT_SUCCESS;
}