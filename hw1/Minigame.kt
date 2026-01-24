import kotlin.random.Random

fun main() {
    val game = BoardGame()
    game.play()
}

class BoardGame {
    private val boardSize = 20
    private val board = createBoard()
    private var playerPosition = 0
    private var playerMoney = 25
    private val winningMoney = 25

    private fun createBoard(): Array<String> {
        return Array(boardSize) {
            listOf("🟫", "🟪", "🟨", "🟩", "🟦").random()
        }
    }

    fun play() {
        println("Welcome to Board Game!")
        println("Reach the end with exactly $winningMoney coins to win!\n")

        while (playerPosition < boardSize - 1) {
            displayBoard()
            println("Current Money: $playerMoney | Position: $playerPosition/${boardSize - 1}")
            println("Press Enter to roll the dice...")
            readLine()

            val diceRoll = rollD6()
            println("You rolled: $diceRoll")

            playerPosition += diceRoll
            if (playerPosition >= boardSize) {
                playerPosition = boardSize - 1
            }

            val moneyChange = Random.nextInt(-5, 6)
            playerMoney += moneyChange
            println("Money change: ${if (moneyChange >= 0) "+" else ""}$moneyChange")
            println("New balance: $playerMoney\n")

            if (playerMoney < 0) {
                println("You're out of money! Game Over!")
                return
            }
        }

        println(board.joinToString(" "))
        println("You reached the end!")
        if (playerMoney >= winningMoney) {
            println("You win with $playerMoney coins!")
        } else {
            println("You lose! You have $playerMoney coins, but need above $winningMoney to win.")
        }
    }

    private fun displayBoard() {
        repeat(playerPosition) { print(board[it]) }
        print("🎮")
        println()
    }

    private fun rollD6(): Int = Random.nextInt(1, 7)
}