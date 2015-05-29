#include <boost/test/unit_test.hpp>
#include <controller_tuning_widgets/Dummy.hpp>

using namespace controller_tuning_widgets;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    controller_tuning_widgets::DummyClass dummy;
    dummy.welcome();
}
