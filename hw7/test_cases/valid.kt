// hw5_tests.kt -- HW5 semantic analysis test cases
// Each section tests a specific requirement.
// Sections marked VALID should produce No errors.
// Sections marked ERROR should produce semantic errors.
// Run each section separately by copying into its own .kt file.

// ============================================================
// TEST 1: VALID -- all base types declared and used correctly
// ============================================================
fun testBaseTypes() {
    val i: Int = 42
    val d: Double = 3.14
    val b: Boolean = true
    val c: Char = 'z'
    val s: String = "hello"
    var arr: Array<Int> = makeArray()
}

// ============================================================
// TEST 2: VALID -- arithmetic with compatible types
// ============================================================
fun testArithmetic(a: Int, b: Int): Int {
    val sum = a + b
    val diff = a - b
    val prod = a * b
    val quot = a / b
    val rem = a % b
    return sum
}

// ============================================================
// TEST 3: VALID -- boolean/relational operators
// ============================================================
fun testRelational(x: Int, y: Int): Boolean {
    val lt = x < y
    val gt = x > y
    val lte = x <= y
    val gte = x >= y
    val eq = x == y
    val neq = x != y
    return lt
}

fun testLogical(a: Boolean, b: Boolean): Boolean {
    val andExpr = a && b
    val orExpr = a || b
    val notExpr = !a
    return andExpr
}

// ============================================================
// TEST 4: VALID -- mutability (var can be reassigned)
// ============================================================
fun testMutability() {
    var x = 10
    x = 20
    x += 5
    x -= 1
    x *= 2
    x /= 3
    x %= 4
}

// ============================================================
// TEST 5: VALID -- nullable types and elvis operator
// ============================================================
fun testNullable(s: String?): String {
    val result = s ?: "default"
    return result
}

fun testNullableParam(n: Int?): Int {
    val safe = n ?: 0
    return safe
}

// ============================================================
// TEST 6: VALID -- built-in functions
// ============================================================
fun testBuiltins() {
    println("hello")
    print("world")
    val line = readln()
    val a = abs(5)
    val m = max(1, 2)
    val n = min(3, 4)
}

// ============================================================
// TEST 7: VALID -- nested calls and expressions
// ============================================================
fun add(x: Int, y: Int): Int {
    return x + y
}

fun testNested(): Int {
    return add(add(1, 2), add(3, 4))
}

fun testNestedBuiltins() {
    println(add(1, 2))
}

// ============================================================
// TEST 8: VALID -- if condition is boolean
// ============================================================
fun testIfCondition(x: Int): Int {
    if (x > 0) {
        return 1
    } else {
        return 0
    }
}

// ============================================================
// TEST 9: VALID -- while condition is boolean
// ============================================================
fun testWhile() {
    var i = 0
    while (i < 10) {
        i++
    }
}

// ============================================================
// TEST 10: VALID -- dot access chain
// ============================================================
fun testDotChain(s: String): Int {
    return s.length
}

// ============================================================
// TEST 11: VALID -- array operations
// ============================================================
fun makeArray(): Array<Int> {
    return []
}

fun testArray(arr: Array<Int>): Int {
    return arr[0]
}