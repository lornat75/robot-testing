// -*- mode:C++ { } tab-width:4 { } c-basic-offset:4 { } indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2015 iCub Facility
 * Authors: Ali Paikan
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */

#include <stdio.h>
#include <TestCase.h>
#include <TestResult.h>
#include <ConsoleListener.h>
#include <TestAssert.h>

using namespace RTF;

class MyTest : public TestCase {
public:
    MyTest() : TestCase("MyTest") {

    }

    virtual ~MyTest() { }

    virtual bool setup() {
        RTF_ASSERT_REPORT("running MyTest::setup...");
        return true;
    }

    virtual void tearDown() {
        RTF_ASSERT_REPORT("running MyTest::teardown...");
        RTF_ASSERT_ERROR("cannot tear down!");
    }

    virtual void run() {

        RTF_ASSERT_REPORT("testing integeres");
        RTF_ASSERT_CHECK(2<3, "is not smaller");
        RTF_ASSERT_CHECK(5<3, "is not smaller");
    }

};

int main(int argc, char** argv)
{
    // create a test listener to collect the result
    ConsoleListener listener(false);

    // create a test result and add the listeners
    TestResult result;
    result.addListener(&listener);

    // calling a test case
    MyTest atest;
    atest.TestCase::run(result);

    return 0;

}
