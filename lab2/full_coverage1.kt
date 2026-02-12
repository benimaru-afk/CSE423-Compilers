// Comprehensive test for k0 lexer - covers all token categories

// Shebang line test
#!/usr/bin/env kotlin

// Import statement
import kotlin.test

// Keywords: fun, val, var, if, else, while, for, return, break, continue, when, in, do
fun testFunction() {
    val x = 5
    var y = 10
    
    // If-else
    if (x < y) {
        println("less")
    } else {
        println("greater")
    }
    
    // While loop
    while (y > 0) {
        y--
        if (y == 3) break
        if (y == 7) continue
    }
    
    // For loop with in and range
    for (i in 1..10) {
        println(i)
    }
    
    // When expression
    when (x) {
        5 -> println("five")
    }
    
    // Do-while
    do {
        x++
    } while (x < 10)
    
    return
}

// Const keyword
const val MAX = 100

// All literals
fun testLiterals() {
    val intLit = 42                    // INTEGERLITERAL
    val realLit = 3.14                 // REALLITERAL
    val boolTrue = true                // BOOLEANLITERAL
    val boolFalse = false              // BOOLEANLITERAL
    val charLit = 'A'                  // CHARACTERLITERAL
    val strLit = "Hello\tWorld\n"      // STRINGLITERAL (with escapes)
    val nullVal = null                 // NULLLITERAL
}

// All assignment operators: =, +=, -=, *=, /=, %=
fun testAssignment() {
    var a = 10        // ASSIGNMENT
    a += 5            // ADD_ASSIGN
    a -= 3            // SUB_ASSIGN
    a *= 2            // MUL_ASSIGN
    a /= 4            // DIV_ASSIGN
    a %= 3            // MOD_ASSIGN
}

// All arithmetic operators: +, -, *, /, %
fun testArithmetic() {
    val sum = 5 + 3        // ADD
    val diff = 5 - 3       // SUB
    val prod = 5 * 3       // MUL
    val quot = 10 / 2      // DIV
    val rem = 10 % 3       // MOD
}

// Increment/decrement: ++, --
fun testIncDec() {
    var x = 5
    x++              // INCR
    x--              // DECR
}

// Comparison operators: ==, !=, <, >, <=, >=
fun testComparison() {
    val eq = (5 == 5)        // EQ
    val neq = (5 != 3)       // NEQ
    val lt = (3 < 5)         // LANGLE (also LT)
    val gt = (5 > 3)         // RANGLE (also GT)
    val lte = (3 <= 5)       // LTE
    val gte = (5 >= 3)       // GTE
}

// Referential equality: ===, !==
fun testRefEquality() {
    val obj1 = "test"
    val obj2 = "test"
    val same = (obj1 === obj2)      // REF_EQ
    val diff = (obj1 !== obj2)      // REF_NEQ
}

// Logical operators: &&, ||, !
fun testLogical() {
    val andResult = (true && false)    // AND
    val orResult = (true || false)     // OR
    val notResult = !true              // NOT (also EXCL)
}

// Null-safe operators: ?., ?:, ?
fun testNullSafe() {
    val str: String? = null
    val len = str?.length              // SAFE_CALL
    val result = str ?: "default"      // ELVIS
    val nullable: Int? = 5             // QUEST
}

// Range operators: .., ..<
fun testRange() {
    val range1 = 1..10                 // RANGE
    val range2 = 1..<10                // RANGE_UNTIL
}

// Type cast: as
fun testTypeCast() {
    val obj: Any = "string"
    val str = obj as String            // AS
}

// Delimiters: (), {}, [], <>, ,, ., :, ;, ->, ::
fun testDelimiters() {
    val list = listOf(1, 2, 3)         // LPAREN, RPAREN, COMMA
    val map = mapOf("key" to "value")  // LCURL, RCURL (in map literal)
    val arr = arrayOf(1, 2, 3)         // LSQUARE, RSQUARE
    val generic: List<Int> = list      // LANGLE, RANGLE
    
    // Lambda with arrow
    val lambda = { x: Int -> x * 2 }   // COLON, ARROW
    
    // Double colon (method reference)
    val ref = String::length           // DOUBLE_COLON
    
    // Semicolon (optional in Kotlin but valid)
    val x = 5; val y = 10;            // SEMI
    
    // Dot for member access
    val len = "test".length            // DOT
}

// Nested block comment test
/*
 * Outer comment
 /* Nested comment */
 * Still in outer comment
 */

// Line comment test
// This is a line comment

/* Multi-line comment
   spanning multiple
   lines */