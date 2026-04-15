fun describe(x: Int) {
    when (x) {
        1 -> println("one")
        2 -> println("two")
        3 -> println("three")
        else -> println("other")
    }
}

fun grade(score: Int) {
    when {
        score >= 90 -> println("A")
        score >= 80 -> println("B")
        score >= 70 -> println("C")
        else -> println("F")
    }
}
