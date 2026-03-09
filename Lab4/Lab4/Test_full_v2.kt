// Test_full_v2.kt — Full coverage test for K0 grammar
// Covers every grammar construct in k0gram.y

import kotlin.math
import java.util.ArrayList

// ─── 1. BASIC FUNCTION — no params, no return type ───────────────────────────
fun main() {
    println("Hello, World!")
}

// ─── 2. FUNCTION — params and return type ────────────────────────────────────
fun add(x: Int, y: Int): Int {
    return x + y
}

// ─── 3. GENERIC PARAM TYPE — Array<Int> ──────────────────────────────────────
fun sumArray(arr: Array<Int>): Int {
    var total = 0
    for (x in arr) {
        total += x
    }
    return total
}

// ─── 4. GENERIC RETURN TYPE — Array<String> ──────────────────────────────────
fun makeArray(): Array<String> {
    var arr: Array<String> = makeArray()
    return arr
}

// ─── 5. NULLABLE GENERIC TYPE — Array<Int>? ──────────────────────────────────
fun maybeArray(flag: Boolean): Array<Int>? {
    if (flag) {
        var arr: Array<Int> = makeArray()
        return arr
    }
    return null
}

// ─── 6. NESTED GENERIC — Map<String, Int> ────────────────────────────────────
fun useMap(m: Map<String, Int>): Int {
    return 0
}

// ─── 7. ALL LITERAL TYPES ─────────────────────────────────────────────────────
fun literals() {
    val a = 10
    val b = 100L
    val c = 3.14
    val d = 2.71
    val e = true
    val f = false
    val g = 'z'
    val h = "hello"
    val i = null
}

// ─── 8. ALL VARIABLE FORMS ───────────────────────────────────────────────────
fun variables() {
    var x: Int = 0
    val y: String = "hi"
    var arr: Array<Int> = makeArray()
    val nullable: Int? = null
    const val MAX = 100
}

// ─── 9. ALL ASSIGNMENT OPERATORS ─────────────────────────────────────────────
fun assignments() {
    var b = 10
    b += 1
    b -= 2
    b *= 3
    b /= 4
    b %= 5
}

// ─── 10. POSTFIX INCREMENT / DECREMENT (spec: postfix only) ──────────────────
fun postfixOps() {
    var x = 0
    x++
    x--
}

// ─── 11. UNARY PREFIX OPERATORS ──────────────────────────────────────────────
fun prefixOps() {
    val a = 5
    val neg = -a
    val pos = +a
    val notTrue = !true
}

// ─── 12. ARITHMETIC OPERATORS ────────────────────────────────────────────────
fun arithmetic(a: Int, b: Int): Int {
    val sum = a + b
    val diff = a - b
    val prod = a * b
    val quot = a / b
    val rem = a % b
    return sum + diff - prod * quot / rem
}

// ─── 13. COMPARISON OPERATORS ────────────────────────────────────────────────
fun comparisons(a: Int, b: Int): Boolean {
    val eq = a == b
    val neq = a != b
    val lt = a < b
    val gt = a > b
    val lte = a <= b
    val gte = a >= b
    val ref = a === b
    val nref = a !== b
    return eq
}

// ─── 14. LOGICAL OPERATORS ───────────────────────────────────────────────────
fun logical(a: Boolean, b: Boolean): Boolean {
    val andExpr = a && b
    val orExpr = a || b
    val notExpr = !a
    return andExpr || orExpr && notExpr
}

// ─── 15. IF / ELSE IF / ELSE ─────────────────────────────────────────────────
fun classify(n: Int): Int {
    if (n > 0) {
        return 1
    } else if (n < 0) {
        return -1
    } else {
        return 0
    }
}

// ─── 16. IF WITHOUT ELSE ─────────────────────────────────────────────────────
fun clamp(x: Int): Int {
    if (x < 0) {
        return 0
    }
    return x
}

// ─── 17. WHILE LOOP ───────────────────────────────────────────────────────────
fun countdown(n: Int) {
    var i = n
    while (i > 0) {
        println(i)
        i--
    }
}

// ─── 18. DO-WHILE LOOP ───────────────────────────────────────────────────────
fun doLoop() {
    var x = 0
    do {
        x++
    } while (x < 10)
}

// ─── 19. FOR-IN WITH RANGE ───────────────────────────────────────────────────
fun forRange() {
    var sum = 0
    for (i in 1..10) {
        sum += i
    }
}

// ─── 20. FOR-IN WITH VARIABLE ────────────────────────────────────────────────
fun forVar(items: List) {
    for (x in items) {
        println(x)
    }
}

// ─── 21. FOR-IN WITH TYPE ANNOTATION ─────────────────────────────────────────
fun forTyped(arr: Array<Int>) {
    for (x: Int in arr) {
        println(x)
    }
}

// ─── 22. RANGE WITH UNTIL (..<) ──────────────────────────────────────────────
fun rangeUntil() {
    for (i in 0..<10) {
        println(i)
    }
}

// ─── 23. IN-RANGE INFIX OPERATOR ─────────────────────────────────────────────
fun inRange(x: Int): Boolean {
    val r = x in 1..100
    return r
}

// ─── 24. ELVIS OPERATOR ──────────────────────────────────────────────────────
fun elvis(s: String?): String {
    val result = s ?: "default"
    return result
}

// ─── 25. SAFE CALL ───────────────────────────────────────────────────────────
fun safeCall(s: String?) {
    val len = s?.length
}

// ─── 26. DOT ACCESS / CHAINING ───────────────────────────────────────────────
fun dotAccess(s: String): Int {
    return s.length
}

// ─── 27. SUBSCRIPT / INDEX ───────────────────────────────────────────────────
fun indexing(arr: Array<Int>): Int {
    return arr[0]
}

// ─── 28. FUNCTION CALLS ──────────────────────────────────────────────────────
fun callExamples() {
    println("test")
    val x = add(1, 2)
    val y = arithmetic(x, 3)
}

// ─── 29. NESTED CALLS ────────────────────────────────────────────────────────
fun nestedCalls(): Int {
    return add(add(1, 2), add(3, 4))
}

// ─── 30. COLLECTION LITERAL ──────────────────────────────────────────────────
fun collections() {
    val empty = []
    val nums = [1, 2, 3, 4, 5]
    val strs = ["a", "b", "c"]
}

// ─── 31. RETURN VARIANTS ─────────────────────────────────────────────────────
fun returnVoid() {
    return
}

fun returnValue(): Int {
    return 42
}

// ─── 32. BREAK AND CONTINUE ──────────────────────────────────────────────────
fun breakContinue() {
    var i = 0
    while (i < 10) {
        i++
        if (i == 3) {
            continue
        }
        if (i == 7) {
            break
        }
    }
}

// ─── 33. NULLABLE TYPE ANNOTATION ────────────────────────────────────────────
fun nullableParam(x: Int?): Int {
    val safe = x ?: 0
    return safe
}

// ─── 34. DOUBLE-COLON REFERENCE ──────────────────────────────────────────────
fun doubleColon() {
    val ref = String::length
}

// ─── 35. COMPLEX EXPRESSIONS ─────────────────────────────────────────────────
fun complexExpr(a: Int, b: Int, c: Int): Int {
    return a + b * c - a / b % c
}

// ─── 36. GROUPED EXPRESSIONS ─────────────────────────────────────────────────
fun grouped(a: Int, b: Int): Int {
    return (a + b) * (a - b)
}

// ─── 37. ARRAY DECLARATION WITH GENERIC INITIALIZER ──────────────────────────
fun arrayInit() {
    var nums: Array<Int> = makeArray()
    var strs: Array<String> = makeArray()
    var matrix: Array<Array<Int>> = makeArray()
}

// ─── 38. CONST VAL AT TOP LEVEL ──────────────────────────────────────────────
const val PI = 3
const val MAX_SIZE = 100
const val APP_NAME = "k0"