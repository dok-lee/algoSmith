/**
 * 1620 : 나는야 포켓몬 마스터 이다솜
 * 입력
 * 첫째 줄에는 도감에 수록되어 있는 포켓몬의 개수 N이랑 내가 맞춰야 하는 문제의 개수 M이 주어져. N과 M은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수인데, 자연수가 뭔지는 알지? 모르면 물어봐도 괜찮아. 나는 언제든지 질문에 답해줄 준비가 되어있어.
 * 둘째 줄부터 N개의 줄에 포켓몬의 번호가 1번인 포켓몬부터 N번에 해당하는 포켓몬까지 한 줄에 하나씩 입력으로 들어와. 포켓몬의 이름은 모두 영어로만 이루어져있고, 또, 음... 첫 글자만 대문자이고, 나머지 문자는 소문자로만 이루어져 있어.
 * 아참! 일부 포켓몬은 마지막 문자만 대문자일 수도 있어. 포켓몬 이름의 최대 길이는 20, 최소 길이는 2야. 그 다음 줄부터 총 M개의 줄에 내가 맞춰야하는 문제가 입력으로 들어와.
 * 문제가 알파벳으로만 들어오면 포켓몬 번호를 말해야 하고, 숫자로만 들어오면, 포켓몬 번호에 해당하는 문자를 출력해야해. 입력으로 들어오는 숫자는 반드시 1보다 크거나 같고, N보다 작거나 같고, 입력으로 들어오는 문자는 반드시 도감에 있는 포켓몬의 이름만 주어져.
 * 그럼 화이팅!!!
 * 출력
 * 첫째 줄부터 차례대로 M개의 줄에 각각의 문제에 대한 답을 말해줬으면 좋겠어!!!. 입력으로 숫자가 들어왔다면 그 숫자에 해당하는 포켓몬의 이름을, 문자가 들어왔으면 그 포켓몬의 이름에 해당하는 번호를 출력하면 돼. 그럼 땡큐~
 *
 * @note 시간 제한 2초를 지키려면 O(n)인 배열만 사용할 수는 없다. map을 활용하고, <string, int>와 <int, string>을 각각 만든다.
 * 예제 입력
26 5
Bulbasaur
Ivysaur
Venusaur
Charmander
Charmeleon
Charizard
Squirtle
Wartortle
Blastoise
Caterpie
Metapod
Butterfree
Weedle
Kakuna
Beedrill
Pidgey
Pidgeotto
Pidgeot
Rattata
Raticate
Spearow
Fearow
Ekans
Arbok
Pikachu
Raichu
25
Raichu
3
Pidgey
Kakuna

 * 예제 출력
Pikachu
26
Venusaur
16
14
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int pokemonNum;
    cin >> pokemonNum;

    map<string, int> pokedexByName;
    map<int, string> pokedexByNum;

    int cases;
    cin >> cases;

    string pokemon;

    for (int i = 0; i < pokemonNum; i++) {
        cin >> pokemon;
        pokedexByName[pokemon] = i + 1;
        pokedexByNum[i + 1] = pokemon;
    }

    for (int i = 0; i < cases; i++) {
        cin >> pokemon;
        if (atoi(pokemon.c_str()) == 0) {
            cout << pokedexByName[pokemon] << endl;
        } else {
            cout << pokedexByNum[atoi(pokemon.c_str())] << endl;
        }
    }
}



// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int pokemonNum;
//     int cases;

//     cin >> pokemonNum;
//     string pokedex[pokemonNum + 1];

//     cin >> cases;

//     for (int i = 1; i <= pokemonNum; i++) {
//         string pokemon;
//         cin >> pokemon;

//         pokedex[i] = pokemon;
//     }

//     cin.ignore();

//     while (cases--) {
//         string targetPokemon;

//         getline(cin, targetPokemon);

//         if (isdigit(targetPokemon[0])) {
//             cout << pokedex[stoi(targetPokemon)] << endl;
//         } else {
//             for (int i = 1; i <= pokemonNum; i++) {
//                 if (pokedex[i].compare(targetPokemon) == 0) {
//                     cout << i << endl;
//                 }
//             }
//         }
//     }

//     return 0;
// }