cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1_Rezantsev_All_Labs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта
set (Vector Vector)
set (VectorLib VectorLib) #Переменная с именем библиотеки
set (Matrix Matrix)
set (MatrixLib MatrixLib)
set (test test)
set (Stack Stack)
set (List List)
set (ListLib ListLib)
set (ArrayList ArrayList)
set (AListLib AListLib)
set (StackLib StackLib)
set (Queue Queue)
set (QueueLib QueueLib)
set (MStack MStack)
set (MStackLib MStackLib)
set (Exception Exception)
set (Polsk Polsk)
set (PolskLib PolskLib) 
set (Polinom Polinom)
set (PolinomLib PolinomLib)
set (Monom Monom)
set (MonomLib MonomLib)
set (SList SList)
set (SListLib SListLib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib
${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(Vector)
add_subdirectory(gtest)
add_subdirectory(test)
add_subdirectory(VectorLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib)
add_subdirectory(Matrix)
add_subdirectory(MatrixLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MonomLib)
add_subdirectory(Monom)
add_subdirectory(MonomLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolinomLib)
add_subdirectory(Polinom)
add_subdirectory(PolinomLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SListLib)
add_subdirectory(SList)
add_subdirectory(SListLib)



include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(List)
add_subdirectory(ListLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/AListLib)
add_subdirectory(ArrayList)
add_subdirectory(AListLib)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(Stack)
add_subdirectory(StackLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(Queue)
add_subdirectory(QueueLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MStackLib)
add_subdirectory(MStack)
add_subdirectory(MStackLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exception)
add_subdirectory(Exception)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolskLib)
add_subdirectory(Polsk)
add_subdirectory(PolskLib)


#target_link_libraries(${Vector} ${VectorLib} ) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}

#target_link_libraries(${Vector} ${MatrixLib} )
#target_link_libraries(${Matrix} ${MatrixLib} )
#target_link_libraries(${Matrix} ${VectorLib} )
#target_link_libraries(${Stack} ${StackLib} )
#target_link_libraries(${MStack} ${MStackLib} )
#target_link_libraries(${Queue} ${StackLib} )
#target_link_libraries(${Queue} ${QueueLib} )
#target_link_libraries(${List} ${ListLib} )
#target_link_libraries(${ArrayList} ${AListLib} )
#target_link_libraries(${Polsk} ${PolskLib} )
#target_link_libraries(${Monom} ${MonomLib}) 
#target_link_libraries(${Polinom} ${PolinomLib} )
#target_link_libraries(${Polinom} ${MonomLib} )
#target_link_libraries(${SList} ${SListLib} )#Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}

#target_link_libraries(${SList} ${ListLib} )


