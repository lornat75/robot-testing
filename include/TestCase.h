// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2015 iCub Facility
 * Authors: Ali Paikan
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */


#ifndef _RTF_TESTCASE_H
#define _RTF_TESTCASE_H

#include <Test.h>
#include <TestResult.h>

namespace RTF {
    class TestCase;
}


/**
 * class TestCase
 */

class RTF::TestCase : public RTF::Test {
public:

    /**
     * TestCase constructor
     * @param  name The TestCase name
     */
    TestCase(std::string name);

    /**
     *  TestCase destructor
     */
    virtual ~TestCase();

    /**
     * @brief setup is called before the test run
     * @return true or false depending of the test initialization
     */
    virtual bool setup();

    /**
     * @brief tearDown is called after the test run
     */
    virtual void tearDown();

    /**
     * @brief run is called by the TestCase class
     * if setup is successfull;
     */
    virtual void run() = 0;

    /**
     * the main caller of a TestCase inherited from Test Class.
     * @param result an instance of a TestResult
     * to collect the result of the test.
     */
    void run(TestResult &result);

    /**
     * @brief succeeded
     * @return true or false representing whether the test
     * was successful or not.
     */
    bool succeeded() const;

    /**
     * @brief failed set the test successful flag to \c false
     *         which indicates that the test was not successful.
     */
    void failed();

    /**
     * @brief getResult returns an instance of TestResult
     * if run(TestResult &result) has been already called
     * by a TestRunner
     * @return an instance of TestResult
     */
    RTF::TestResult* getResult();

private:
    RTF::TestResult* result;
    bool successful;
};
#endif // _RTF_TESTCASE_H
