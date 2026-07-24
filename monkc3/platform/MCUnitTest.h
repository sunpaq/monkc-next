#ifndef WIN32

#include <assert.h>
#include "MCContext.h"
#include "MCException.h"
/* Assert Functions */
//void assert( int expression);
//all the exception will be catched inside the MCUnitTestCase, user should not catch them
void assertYES(int expression) throws(MCAssertYESException);
void assertNO(int expression) throws(MCAssertNOException);
void assertNil(void* ptr) throws(MCAssertNilException);
void assertNotNil(void* ptr) throws(MCAssertNotNilException);
void assertSame(struct MCObject* obj1, struct MCObject* obj2) throws(MCAssertSameException);
void assertNotSame(struct MCObject* obj1, struct MCObject* obj2) throws(MCAssertNotSameException);
void assertEquals(int exp1, int exp2) throws(MCAssertEqualsException);
void fail(char* message);

/* Test Result */

#ifndef MCUnitTestResult_
#define MCUnitTestResult_

structure(MCUnitTestResult, MCObject)
	fundef(addSuccessInfo, void), char* succinfo endfun;
	fundef(addFailInfo, void), char* failinfo endfun;
end;

constructor(MCUnitTestResult)endfun;

#endif

/* Test Case */

#ifndef MCUnitTestCase_
#define MCUnitTestCase_ 

structure(MCUnitTestCase, MCObject)
	struct MCUnitTestResult* unitTestResultRef;
	struct MCUnitTestCase* next_case;

	fundef(initWithTestResult, struct MCUnitTestCase*), struct MCUnitTestResult* resultRef endfun;
	fundef(setUp, void)endfun;
	fundef(tearDown, void)endfun;
	fundef(runTests, void)endfun;
	fundef(runATestMethod, void), char* methodName endfun;
	fundef(release, void)endfun;
end;

constructor(MCUnitTestCase)endfun;

#endif

/* Test Suite */

#ifndef MCUnitTestSuite_
#define MCUnitTestSuite_

structure(MCUnitTestSuite, MCObject)
	struct MCUnitTestCase *first_case;
	struct MCUnitTestCase **last_case_p;
	int test_case_count;
	struct MCUnitTestSuite* next_suite;

	fundef(addTestCase, void), struct MCUnitTestCase* volatile tcase endfun;
	fundef(runTestCases, void)endfun;
	fundef(release, void)endfun;
end;

constructor(MCUnitTestSuite)endfun;

#endif

/* Test Runner */

#ifndef MCUnitTestRunner_
#define MCUnitTestRunner_

structure(MCUnitTestRunner, MCObject)
	struct MCUnitTestResult* unitTestResult;
	struct MCUnitTestSuite* first_suite;
	int test_suite_count;

	fundef(addTestSuite, void), struct MCUnitTestSuite* testSuite endfun;
	fundef(runTestSuites, void)endfun;
	fundef(release, void)endfun;
end;

constructor(MCUnitTestRunner)endfun;

#endif

#endif
