// 문제 링크: https://www.acmicpc.net/problem/1931
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    // 입력을 위한 bufferReader
    val br = BufferedReader(InputStreamReader(System.`in`))
    // 오름차순 정렬을 위한 lambda
    var lambda = {a:Int, b:Int ->
        when {
            a < b -> -1
            a > b -> 1
            else -> 0
        }
    }
    // first: 시작시간, second: 종료시간
    // second 시간을 오름차순으로 정렬하고,
    // second가 같은 경우 first를 오름차순으로 정렬
    val pq = PriorityQueue<Pair<Int, Int>>(Comparator<Pair<Int, Int>>{a, b
        ->
        when {
            a.second != b.second -> lambda(a.second, b.second)
            else -> lambda(a.first, b.first)
        }
    })

    // 입력
    var curTime = 0
    var answer = 0
    val n:Int = br.readLine()!!.toInt()
    for (i in 1..n) {
        val input = br.readLine()
        val fromto = input.split(' ')
        pq.add(Pair(fromto[0].toInt(),fromto[1].toInt()))
    }

    while (pq.isNotEmpty()) {
        if (pq.peek().first >= curTime) {
            curTime = pq.peek().second
            answer++
        }
        pq.remove()
    }
    println(answer)
}