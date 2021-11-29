/**
 *
 *  作者: hm
 *
 *  说明: 同步计数器
 *
 */


#include "latch.h"


TOOLKIT_TEST_CASE(Latch, Latch)
{
	bool running = true;

	tinyToolkit::util::CountDownLatch latch(2);

	std::thread waitThread([&]
	{
		latch.Wait();

		running = false;
	});

	std::thread consumeThread_1([&]
	{
		while (running)
		{
			latch.CountDown();

			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});

	std::thread consumeThread_2([&]
	{
		while (running)
		{
			latch.CountDown();

			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});

	waitThread.join();

	consumeThread_1.join();
	consumeThread_2.join();

	TOOLKIT_EXPECT_FALSE(running);
}
