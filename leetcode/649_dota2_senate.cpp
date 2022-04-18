/**
https://leetcode.com/problems/dota2-senate/

In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:
Dota2 seneta 는 두 가지의 senetor를 가지고 있다. Seneta는 Dota2 게임에서 변화를 결정하려고 한다. 이 변화의 투표는 round-based 절차로 진행한다. 매 round 마다, 각 senetor는 두 가지 권리 중에 한 가지를 행사할 수 있다.

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Senetor의 권리에 반대 : Senetor는 현 round과 따라오는 모든 round에서 반대되는 senetor의 모든 권리를 잃게 만들 수 있다.
승리를 공표 : 만약 현 senetor가 같은 파티에서 투표할 권리를 가지고 있는 senetor를 찾는다면 그는 승리를 공표하고 이 게임에서 변화를 결정할 수 있다.

Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.
주어진 문자열은 각 senator의 파티가 어디에 속하는지 표현한다. R과 D 문자를 각각 Radiant 파티와 Dire 파티를 의미한다. N seneator가 있다면, 주어지는 문자열 또한 n 이다.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.
Round-based 절차는 첫 번째 seneator 에서 시작해 마지막 senator 까지 주어진 순서대로 진행한다. 이 절차는 투표의 마지막까지 이어진다. 모든 권리를 잃은 senator는 절차 중에 제외된다.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".
모든 senator 가 충분히 지혜롭고 자신의 가장 좋은 전략을 구사한다고 가정한다. 누가 마지막까지 승리해서 Dota2 게임을 바꿀지 예측하라. 결과는 Radiant 혹은 Dire 이다.

 
Example 1:
Input: senate = "RD"
Output: "Radiant"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.


Example 2:
Input: senate = "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
class Solution {
public:
  bool samePartyRemained(string& s) {
    int len = s.length() -1;
    for (int i = 0 ; i < len ; i++) {
      if (s[i] != s[i+1]) {
        return false;
      }
    }
    return true;
  }
  string predictPartyVictory(string senate) {
    string s(senate);
    int index = 0;
    do {
      if (index == s.length()-1) {
        if (s[index] != s[0]) {
          cout << "Erase!!" << endl;
          s.erase(0, 1);
          cout << "After erase s : " << s << endl;
        }
        if (!samePartyRemained(s)) {
          index = 0;
          continue;
        }
      } else {
        if (s[index] != s[index+1]) {
          cout << "Erase 111 !!!" << endl;
          s.erase(index+1, 1);
        }
      }
      index++;
      cout << "s : " << s << " , index : " << index << " , s.length() : " << s.length() << endl;
    } while(s.length() != 1 && index <= s.length()-1);

    cout << "completed, s : " << s << endl;
    if (s[0] == 'R') {
      return "Radiant";
    } else if (s[0] == 'D') {
      return "Dire";
    }
    return "";
  }
};
*/

class Solution {
public:
    string predictPartyVictory(string senate) {
        // rrddd
        // just ban whoevers next
        int rc = 0, dc = 0;
        for (char c : senate) c == 'R' ? rc++ : dc++;
        cout << "rc : " << rc << " dc : " << dc << endl;
        int rk = 0, dk = 0;
        int i = 0, n = senate.size();
        while (rc > 0 && dc > 0) {
            cout << "rc : " << rc << " dc : " << dc << ", rk : " << rk << ", dk: " << dk << " ,i : " << i << endl;
            if (senate[i] == '*');
            else if (senate[i] == 'R' && rk > 0) { rk--; senate[i] = '*'; rc--;}
            else if (senate[i] == 'D' && dk > 0) { dk--; senate[i] = '*'; dc--;}
            else {senate[i] == 'R' ? dk++ : rk++;}
            i = (i+1)%n;

          cout << "senate : " << senate << " i : " << i << endl;
        }
        return rc > 0 ? "Radiant" : "Dire";
    }
};

int main() {
  Solution s;
  if (s.predictPartyVictory("RD") == "Radiant") {
    cout << "Exam1 succeeded" << endl;
  } else {
    cout << "Exam1 failed" << endl;
  }

  if (s.predictPartyVictory("RDD") == "Dire") {
    cout << "Exam2 succeeded" << endl;
  } else {
    cout << "Exam2 failed" << endl;
  }

  if (s.predictPartyVictory("DDRRRR") == "Radiant") {
    cout << "Exam3 succeeded" << endl;
  } else {
    cout << "Exam3 failed" << endl;
  }

  if (s.predictPartyVictory("DDRRR") == "Dire") {
    cout << "Exam4 succeeded" << endl;
  } else {
    cout << "Exam4 failed" << endl;
  }
  return 0;
}