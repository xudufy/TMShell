cd $(dirname $0)

java -jar 3rdParty/antlr/antlr-4.9.2-complete.jar -Dlanguage=Cpp -visitor -no-listener -o parser -package tmshell grammar/TMSlang.g4