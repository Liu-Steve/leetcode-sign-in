#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<ll, int> memory;

class DinnerPlates
{
private:
    int cap;                 // capacity
    vector<stack<int>> line; // stacks
    set<int> not_full;       // idx < nxt and not full
    int nxt;                 // idx after the last not empty stack

public:
    DinnerPlates(int capacity)
    {
        cap = capacity;
        nxt = 0;
        not_full.emplace(INT32_MAX);
    }

    void push(int val)
    {
        if (*not_full.begin() >= nxt)
        {
            if (line.size() <= nxt)
                line.emplace_back();
            line[nxt].emplace(val);
            if (cap != 1)
                not_full.emplace(nxt);
            nxt++;
            return;
        }
        int sel = *not_full.begin();
        line[sel].emplace(val);
        if (line[sel].size() < cap)
            return;
        else if (line[sel].size() > cap)
            cout << "ERR" << endl;
        not_full.erase(sel);
    }

    int pop()
    {
        if (nxt == 0)
            return -1;
        int ans = line[nxt - 1].top();
        line[nxt - 1].pop();
        not_full.emplace(nxt - 1);
        while (nxt > 0 && line[nxt - 1].size() == 0)
            nxt--;
        return ans;
    }

    int popAtStack(int index)
    {
        if (index >= nxt)
            return -1;
        if (index == nxt - 1)
            return pop();
        if (line[index].size() == 0)
            return -1;
        int ans = line[index].top();
        line[index].pop();
        not_full.emplace(index);
        return ans;
    }
};

void exe()
{
    vs op = {"DinnerPlates", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "popAtStack", "push", "popAtStack", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "push", "push", "push", "push", "push", "push", "push", "push", "popAtStack"};
    vi num = {{1}, {3333}, {6171}, {2289}, {5635}, {7054}, {5338}, {2466}, {2642}, {5612}, {8830}, {6311}, {2733}, {8866}, {9379}, {158}, {4218}, {6375}, {6554}, {6214}, {8452}, {4982}, {1525}, {5926}, {8457}, {3039}, {7854}, {2295}, {795}, {2341}, {3376}, {8662}, {6847}, {6702}, {1948}, {4755}, {1186}, {4231}, {4598}, {6436}, {2735}, {1325}, {7318}, {8866}, {647}, {9148}, {2463}, {6951}, {9896}, {7692}, {4276}, {945}, {843}, {2390}, {7955}, {2524}, {7761}, {4321}, {6975}, {4543}, {2750}, {6775}, {1038}, {1335}, {908}, {5876}, {1594}, {7822}, {2624}, {597}, {4863}, {1771}, {2361}, {5258}, {7382}, {2364}, {891}, {37}, {7485}, {1241}, {2921}, {8632}, {1617}, {1959}, {6382}, {7265}, {4459}, {2599}, {719}, {4801}, {4574}, {5873}, {3711}, {3908}, {3424}, {633}, {2394}, {6438}, {7287}, {1565}, {8819}, {7506}, {2220}, {9838}, {9895}, {713}, {2802}, {7265}, {4966}, {8552}, {2154}, {4725}, {520}, {5003}, {7070}, {4365}, {52}, {8565}, {62}, {2969}, {4709}, {8728}, {9529}, {5332}, {8108}, {1436}, {1665}, {1251}, {6642}, {906}, {8478}, {3451}, {4911}, {1175}, {3030}, {8093}, {1259}, {2189}, {3360}, {8398}, {7734}, {7181}, {8760}, {9679}, {6567}, {482}, {9913}, {9338}, {9573}, {804}, {9015}, {8877}, {3095}, {8221}, {9910}, {7269}, {9053}, {5310}, {3360}, {2008}, {1983}, {4101}, {509}, {4474}, {6315}, {4650}, {2627}, {8068}, {9534}, {3212}, {1180}, {8063}, {996}, {6337}, {8941}, {3721}, {747}, {5167}, {3151}, {9316}, {8642}, {3895}, {6215}, {5343}, {8355}, {2367}, {4413}, {6495}, {3892}, {1125}, {3720}, {9062}, {2777}, {4620}, {6922}, {7139}, {4327}, {6925}, {6778}, {3648}, {719}, {1564}, {3754}, {8904}, {4438}, {6744}, {778}, {6300}, {9134}, {1687}, {8637}, {8963}, {2786}, {1292}, {1688}, {997}, {1708}, {824}, {9715}, {6150}, {9454}, {2551}, {831}, {769}, {9646}, {423}, {5131}, {6880}, {2742}, {9735}, {9535}, {127}, {8846}, {30}, {5414}, {9105}, {1276}, {2204}, {6373}, {7677}, {5710}, {421}, {8997}, {2430}, {9483}, {8273}, {5625}, {7190}, {2688}, {5824}, {3336}, {6249}, {3778}, {9804}, {6639}, {3940}, {8556}, {7287}, {4231}, {7711}, {8880}, {5513}, {1955}, {7937}, {1638}, {7758}, {1918}, {249}, {871}, {1702}, {5629}, {3431}, {2129}, {7898}, {1790}, {4319}, {7602}, {2475}, {7722}, {6843}, {4340}, {5590}, {8272}, {6370}, {2812}, {7961}, {3424}, {8429}, {3431}, {9034}, {1216}, {3947}, {771}, {1600}, {504}, {2814}, {1044}, {919}, {8677}, {5164}, {1745}, {3697}, {9884}, {9696}, {7113}, {2955}, {9880}, {1025}, {9864}, {3370}, {1935}, {1527}, {1403}, {9715}, {395}, {2154}, {8415}, {2590}, {2132}, {5570}, {2184}, {3522}, {7332}, {6533}, {9289}, {2682}, {6250}, {9482}, {6704}, {7265}, {9650}, {6430}, {4307}, {2188}, {2573}, {529}, {1501}, {1191}, {2718}, {1977}, {9451}, {4673}, {4847}, {2256}, {7647}, {8013}, {7355}, {2065}, {1568}, {9298}, {9329}, {5455}, {5288}, {4139}, {5319}, {414}, {8230}, {3388}, {116}, {1148}, {2264}, {1127}, {9308}, {9574}, {1370}, {6984}, {1214}, {8152}, {7425}, {8435}, {7755}, {3393}, {8326}, {1709}, {2983}, {4902}, {862}, {4005}, {4209}, {8382}, {1046}, {8943}, {3251}, {4166}, {8595}, {2030}, {9785}, {7720}, {1524}, {2570}, {3746}, {460}, {8308}, {7439}, {1537}, {5188}, {5095}, {2147}, {3657}, {1690}, {4215}, {9049}, {8994}, {1783}, {8201}, {7512}, {1202}, {3724}, {972}, {4872}, {8338}, {1448}, {1779}, {2229}, {351}, {7779}, {4629}, {5343}, {1963}, {2383}, {3825}, {7964}, {1825}, {6084}, {1492}, {9022}, {8911}, {1910}, {7142}, {3394}, {745}, {1522}, {3314}, {7203}, {200}, {1961}, {4587}, {6933}, {2377}, {7378}, {8068}, {4706}, {6535}, {2491}, {9006}, {3293}, {9608}, {7635}, {4435}, {809}, {5457}, {1161}, {5855}, {458}, {8055}, {8869}, {2182}, {7596}, {6829}, {2437}, {8595}, {5565}, {6069}, {8861}, {3819}, {7896}, {5165}, {2482}, {3383}, {1792}, {3450}, {1133}, {739}, {7392}, {7124}, {8641}, {8638}, {9364}, {4781}, {5889}, {9617}, {1526}, {3014}, {8916}, {1467}, {7436}, {9796}, {5553}, {2132}, {1228}, {3852}, {2082}, {3964}, {8412}, {8397}, {5906}, {6149}, {7866}, {9240}, {5140}, {8673}, {1785}, {3342}, {5231}, {5212}, {9871}, {1493}, {1042}, {1721}, {227}, {9920}, {2601}, {5929}, {9408}, {141}, {3296}, {3648}, {9984}, {7029}, {4020}, {7735}, {7092}, {4729}, {7318}, {5490}, {7491}, {3372}, {6018}, {5069}, {7615}, {9495}, {1003}, {2508}, {2835}, {8726}, {6213}, {373}, {864}, {2282}, {7643}, {1733}, {9066}, {9034}, {5580}, {1385}, {1624}, {5278}, {5625}, {3558}, {378}, {6525}, {1758}, {6640}, {3691}, {3136}, {5031}, {474}, {8177}, {2734}, {89}, {3837}, {8727}, {559}, {8667}, {9157}, {3137}, {1322}, {1062}, {584}, {4358}, {5775}, {9639}, {4547}, {7117}, {9650}, {2105}, {1824}, {5389}, {1563}, {544}, {9570}, {5303}, {6506}, {8135}, {1583}, {372}, {5836}, {5635}, {6542}, {4518}, {5739}, {5500}, {7938}, {1032}, {176}};
    cout << op.size() << ' ' << num.size() << endl;
    int len = min(op.size(), num.size());

    DinnerPlates d(num[0]);
    for (int i = 1; i < 233; ++i)
    {
        cout << i << ": ";
        if (op[i] == "push")
            d.push(num[i]);
        else if (op[i] == "pop")
            cout << d.pop();
        else
            cout << d.popAtStack(num[i]);
        cout << endl;
    }
}

int main()
{
    io;

    // exe();

    DinnerPlates d(1);
    d.push(1);
    d.push(2);
    d.push(3);
    cout << d.popAtStack(1) << endl;
    d.push(4);

    // DinnerPlates d(2);
    // d.push(1);
    // d.push(2);
    // d.push(3);
    // d.push(4);
    // d.push(5);
    // cout << d.popAtStack(0) << endl;
    // d.push(20);
    // d.push(21);
    // cout << d.popAtStack(0) << endl;
    // cout << d.popAtStack(2) << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;

    // DinnerPlates d(2);
    // d.push(373);
    // d.push(86);
    // d.push(395);
    // d.push(306);
    // d.push(370);
    // d.push(94);
    // d.push(41);
    // d.push(17);
    // d.push(387);
    // d.push(403);
    // d.push(66);
    // d.push(82);
    // d.push(27);
    // d.push(335);
    // d.push(252);
    // d.push(6);
    // d.push(269);
    // d.push(231);
    // d.push(35);
    // d.push(346);
    // cout << d.popAtStack(4) << endl;
    // cout << d.popAtStack(6) << endl;
    // cout << d.popAtStack(2) << endl;
    // cout << d.popAtStack(5) << endl;
    // cout << d.popAtStack(2) << endl;
    // cout << d.popAtStack(2) << endl;
    // cout << d.popAtStack(7) << endl;
    // cout << d.popAtStack(9) << endl;
    // cout << d.popAtStack(8) << endl;
    // cout << d.popAtStack(1) << endl;
    // d.push(474);
    // d.push(216);
    // d.push(256);
    // d.push(196);
    // d.push(332);
    // d.push(43);
    // d.push(75);
    // d.push(22);
    // d.push(273);
    // d.push(101);
    // d.push(11);
    // d.push(403);
    // d.push(33);
    // d.push(365);
    // d.push(338);
    // d.push(331);
    // d.push(134);
    // d.push(1);
    // d.push(250);
    // d.push(19);
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;
    // cout << d.pop() << endl;

    return 0;
}
