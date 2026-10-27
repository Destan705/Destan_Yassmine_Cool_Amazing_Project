#include <gtest/gtest.h>
#include <vector>
#include "event_dispatcher.h"

TEST(EventDispatcherTest, SubscribeReturnsDifferentIds) {
    // TODO: make an EventDispatcher
    EventDispatcher dispatcher;
    // TODO: subscribe an empty lambda, save the ID
    auto id1 = dispatcher.subscribe([](const SceneChangedEvent&) {});
    // TODO: subscribe another empty lambda, save the ID
    auto id2 = dispatcher.subscribe([](const SceneChangedEvent&) {});
    // TODO: EXPECT the two IDs are different
    EXPECT_NE(id1, id2);
}

TEST(EventDispatcherTest, DispatchCallsListenersInOrder) {
    // TODO: make an EventDispatcher
    // TODO: make a std::vector<int> called order
    // TODO: subscribe a lambda that pushes 1 into order
    // TODO: subscribe a lambda that pushes 2 into order
    // TODO: dispatch a SceneChangedEvent
    // TODO: EXPECT order is {1, 2}
}

TEST(EventDispatcherTest, UnsubscribedListenerIsNotCalled) {
    // TODO: make an EventDispatcher
    // TODO: make a bool called = false
    // TODO: subscribe a lambda that sets called = true, save the ID
    // TODO: unsubscribe that ID
    // TODO: dispatch a SceneChangedEvent
    // TODO: EXPECT called is still false
}