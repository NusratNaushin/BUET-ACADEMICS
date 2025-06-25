source ./antlr4_venv/bin/activate
cd antlr4-resources/antlr4-skeletons/cpp
bash clean-script.sh
 bash run-script.sh input/test_syntax_error.c
