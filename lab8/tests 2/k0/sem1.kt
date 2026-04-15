fun countdown(n: Int) {
    var i = n
    while (i > 0) {
        println(i)
        i--
    }
}

fun jumps() {
    var i = 0
    while (i < 10) {
        if (i == 3) {
            i++
            continue
        }
        if (i == 7) {
            break
        }
        i++
    }
    return
}
