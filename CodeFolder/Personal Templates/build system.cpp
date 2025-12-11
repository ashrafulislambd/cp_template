// * Sublime Text Build System *
{
  "shell_cmd": "g++ $file -o $file_base_name && ./$file_base_name< input.txt > output.txt && rm $file_base_name",
  "working_dir": "$file_path",
  "selector": "source.c++"
}

{
    "cmd": [
        "g++",
        "-std=c++14",
        "-DSONIC",
        "$file_name",
        "-o",
        "$file_base_name",
        "&&",
        "timeout",
        "4s",
        "./$file_base_name< inputf.in > outputf.in"
    ],

    "selector": "source.cpp",
    "file_regex": "^(.*?):([0-9]+):([0-9]+)?:?(.*)$",
    "shell": true,
    "working_dir": "$file_path"
}