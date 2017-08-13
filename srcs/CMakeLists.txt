add_executable(factory factory.cpp)

add_executable(strategy strategy.cpp)
add_executable(strategy_factory strategy_factory.cpp)
add_executable(decorator decorator.cpp)
add_executable(proxy proxy.cpp)
add_executable(factory_method factory_method.cpp)
add_executable(prototype prototype.cpp)

add_executable(template_method template_method.cpp)

add_executable(facade facade.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")

add_executable(builder builder.cpp)
add_executable(builder0 builder0.cpp)
add_executable(observer observer.cpp)
add_executable(observer1 observer1.cpp)

add_executable(abstract_factory abstract_factory.cpp)
add_executable(state state.cpp)

add_executable(adapter adapter.cpp)
add_executable(adapter1 adapter1.cpp)
add_executable(memento memento.cpp)

add_executable(composite composite.cpp)

add_executable(composite1 composite1.cpp)
add_executable(singleton singleton.cpp)
add_executable(bridge bridge.cpp)
add_executable(command command.cpp)
add_executable(responsibility_chain responsibility_chain.cpp)

add_executable(mediator mediator.cpp)
add_executable(flyweight flyweight.cpp)
add_executable(interpretor interpretor.cpp)
add_executable(visitor visitor.cpp)
add_executable(iterator iterator.cpp)
add_executable(iterator1 iterator1.cpp)
add_executable(iterator2 iterator2.cpp)


#add_executable(countdownlatch_test1 CountDownLatch_test1.cc)
#target_link_libraries(countdownlatch_test1 muduo_base)
