cmake_minimum_required(VERSION 3.13)
project(simulator)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3 -O0")

add_executable(simulator main.cpp ShuntingYard.cpp ShuntingYard.h Expression.h BinaryExpression.cpp BinaryExpression.h Div.cpp Div.h Plus.cpp Plus.h Minus.cpp Minus.h Mult.cpp Mult.h Number.cpp Number.h Lexer.cpp Lexer.h Command.h OpenDataServerCommand.cpp OpenDataServerCommand.h Parser.cpp Parser.h WhileCommand.cpp WhileCommand.h CommandSleep.cpp CommandSleep.h CommandExpressionFactory.cpp CommandExpressionFactory.h CommandExpression.cpp CommandExpression.h SymTbl.cpp SymTbl.h SymVal.cpp SymVal.h PathSymVal.cpp PathSymVal.h FSParamMap.cpp FSParamMap.h DoubleSymVal.cpp DoubleSymVal.h AssignCommand.cpp AssignCommand.h DefineVarCommand.cpp DefineVarCommand.h SymbolExpression.cpp SymbolExpression.h ConditionCommand.cpp ConditionCommand.h IfCommand.cpp IfCommand.h VarSymVal.h VarSymVal.cpp Client.cpp Client.h ExitCommand.cpp ExitCommand.h ConnectCommand.cpp ConnectCommand.h Server.cpp Server.h PrintCommand.cpp PrintCommand.h)
