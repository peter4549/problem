import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val word = scanner.nextLine().toUpperCase()

    if (word.length == 1) {
        print(word)
        return
    }

    val map = mutableMapOf<Char, Int>()

    for (i in word)
        map[i] = map.getOrDefault(i, 0) + 1

    val sortedList = map.toList().sortedWith(compareByDescending { it.second })

    if (sortedList[0].second == sortedList[1].second)
        print("?")
    else
        print(sortedList[0].first)
}
