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

class Solution
{
public:
    string lastSubstring(string &s)
    {
        int n = s.size();
        int i = 0;
        int j = 1;
        int k = 0;
        while (j + k < n)
        {
            if (s[i + k] == s[j + k])
            {
                k++;
            }
            else if (s[i + k] < s[j + k])
            {
                i += k + 1;
                if (j <= i)
                    j = i + 1;
                k = 0;
            }
            else
            {
                j += k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};

int main()
{
    io;
    Solution s;
    string s1 = "sabsabsabc";
    cout << s.lastSubstring(s1) << endl;
    string s2 = "pgtrdjdpscrwjifnrcttyruighgygsuvlhxpckkeahrupvnhlnpulyogsbktcuxnmnbmgadksxdjunqvmzyujynwzevtstjvzkddxjjmbgxfueteeuktvcbvypbdnzostbwxmxdwomguuymexfrrwuvuglgwmmwpkrqrpuzvjujksdwopsqlsrfgyzhymfgejuwhyvoqoxluvsdnmkglypoozrcgnzchpurezauixujddjjawqiaasvhrhfbhsqutgskudpcbqkkrcagrtalnsecxmlbiysgabvjbwpfufiwqdsnwbutashtejpmcypfztbgzuxwfcpkwdzhvfxbtvdvdaufjpqgfgxufhsopvwmgekcjejdlgxtdghmyzvopqkdzpuudyunnafvaeyshluuujkqncyigweelxmvgiaegonqmouaxwaqxhnnvaeuppsritdsymdwonbooswiolhbacpnehyvbhekxqxuvpnaxrfgeyixmurlgszqrotqynvtlbpjhhwdkbneiutmwutiyqegkxsrgldqvziysvihgbplhiumonlzlfzbuavbygmltdnfwjbspfpmzkfryjjpswihwixmbeodfpnmytccdvjnctzkxuqrvgjehodfdhpconhfpnatzzxyqkzjttgnwvxcfwyhlajvuhjonbpkvbbahlbybvvnhrwnnpnagtnnqcewzdzsxjgfoqbipohzsgpmyhqgvvnffjumirbhpbfletvcglthgwdvkgczucreovnfpbugyzuugqodpgsylfwyjucfnxjbghurnrkkuwsjfxeoxyzvltwhzyuechbfwstfovqgxngcwsmqsbzasrfrdvjcgedacvviihnzlijbaotpkvzmfejtfsnljthmzfhsrtieqlfhuatdwhcvsoxyphqsoxaqiqjcbuldswtjsukvcoowyfgmixswlyvkllvdtnerfisymrwgtfleupfxxswdlhvioeilstdlqfckoxpohcgnfannhbeeyzthhmszdphsbhjhxbwmjcknyrcsxgxcgnrvqnrlpqqwilhradmbowdvpusmombllpjikbuokakqzovmtmanaavururxjjxvrdnwabfwchkscmmmyixmjtogqgowbqlymnjcalxkmolmhyalvaftbcsidbmyfxshzdbwsfkvlnunvxzadljqngnnhjmlhfpmwnhvvwaokxxyfslhgggpjnhkyzdqgjdsrtaohqaryixzpyrkjumnphvfpsldrcjhxqjisogvybchagdnoezpvehagcqxarruqncmjifvxxvpbsygkzttmnykeptvbxmjsewbppcciomuyuowzbankzklnnxmnxiztfpfcnddaghyuxgaxmgphspocmpcucxkazeakifbsvnatqcvbeywbxsocgyxiawvmljwmokhbpzvijuckbqrjsdtntlriqgyjznvkkeoszsqsonjlsmxhawqqbdwixvnyemiypirwnoyhvfhbbbkcuyuuepobvrspotbbuvtmpykalufsvizvcelblhokldaymsgqasbobwyxnmcqvzqyldgmimsolloudxkjmiyekaiierxwwflmanqkovzxewrrfipzrclqvedftsuswanhfbcmjigxuxaguasfjypjjrgddnwnrfoazbvezxopumretyqfzqyosmvqjpqnuodylrkucrbhtrljryryewvfbnfwjldgjidvucotlvnsvqyjqwfmqhydttjaapqfdmvcytqpcjkqqrhwfiimbvlkvnvtghrggkjppaduhqpdneeejpqrxbnnenvobcgreldbnzpzrwxvkscywgekcnqnkgngokryvfgthpeggwroimsrwwvfmburaaqrzcmtctfxgrlhzbgixfkdjuerowuvtkmawtsrjzucrniwyzeauuizmfdlufwzqotupmykssvwaqljbiegvbonhqaekpeknpvkzgerjljgridlosexgtjkxnnjcqiahuvwvewsjmxbdhsemaoqsfsgxwghtskfxxxtohbqkascghktyxjeznuhguhvkhkhrgxvfjvktljkvmvkrikybfhjrleqxrwvyevynaprnumwpoazwmbevifrcbcckwmhcqrzgyywxlvxjmckmrfitvkelvoubqmflpmuhlwcjtcokvourxueatywmbsgbtcqzmekogznpbqsahgubnsfzfrvlgqvdsqcjptjkztcwbdciaivtwzavpzxgnbtscpzmffbwzezpijzcxnehhecsdyxabdupyqrfxywcikihubgfwrllhdmampqzewshiumisbuabzuthodmfjczwvwwbxbtadhhqqyqdzrfgzlbtlrtayrflxuehrxmggtbglsijmqiozpaydqxcewzizkdauybxbxhekppdxwnrwuchqotbsvatsxallqoatgdlarcoakioexnkugtpdldgzwnjmrdxtaheygwqmesdtinktgfxwsdibsyqyqdypwpzxucwefnzhfwjcnecbhtpuhcmvnyczwlozxlnsiizeteykfiitgyfqjbsoxvtumabgjhaquojutgxzqniiiisqhixjpcnhvopknagkmbuyqbbhlgaqhrnedonfsinfpywjvncbefkdwiidrmjtfunjhbcyvwnbiffildglmcspbmumhyewizqgfwuvbqawruppyjfkmthxpocpbduzqvecdapdjmiuvzduavdasropcdfmrzdfwkisetbznqubivoqkzvxhiuxowfmrsuevnllosjzzeajuxvvayugkzolddxbhyetzqkrxeyomyjidrculppuxxyuswfzkawloetbximriowohrduwpecmczgurxippfecsdrpybwjhbutwgqqrzckigaqevdazolffbffhpmklobchtddrbaqwfddkizyyhpowbgjiswezvhljhcjmetduxyawxjlzthhuplzwidbcbckqxmnitrniupkrqmzxdyctxgaagizoxgpjcedyuewibyalsvlshpngreerfzrqfloevdearlhcdwmxyjoqozxljgbgnccdefycdrqseaqsybwkvzeeccvkpmvpumlhjhsbaenzpbswpcgnxcvkdwllgwubibjaoiadzndfcodoaczxlugycuhdnkcvxjfzptwutlocwctpdfzfkygjrqxavotfrdlmazcfyjsrffzpnzfmuywpjkgywelrhiejhzeuagmlnefnmpscwcpjlcwbkgqwmohylgekxctqmitgtialbugksfirpemtpeixcypilupvlyppqalshwfeeqsqvjorfmpixdzlbiuxmshemapxjrmxhzkrquumpoiqzdgqldzfqohqyfhjeucjsuvjqtlyopxvgauncwthkcuxrtnsobcpkohuygbgltmgogainwmgebuiesejbwgajeaxhbegysmgfhiqdbpgbzsirzjntnfcvjlrqrstbxgznqzzzlxmkwbpvocrzeyquurrjnoblqeohyqfjhmsakicpazwvbvoouiytydwerlxzffwljqtqcwzytmdbpfloyfoixpqivuatqunngyazxvxdnyxhuahilvwnnmhimgxyvtopgsspwzubozebxefsmvsccyiykpoldfmmrnaywhbkcpgjvhuoclwxkxlbszuasmhynflhldmkkecgxjliseppoqrieqwtjkqidksvxctztcpjgedhsgnarqwyliuwbioarpurqdgubcowdepthbqxrtaxzatwzzoxbyuvinokysodoumpztnvcwtsbicuvtvqxszfdpcfdofzkcyqtojcywcsbijvsgitjbdpmqowvvdtllgdbdotqmkgklpizyltljyfdvmluinspznkutjlhwsfudbwiyrmisaqgjlhcneqnoeqrmsztwdkhjqorbfxpkzkihjpgdggwbajszidcvufnjyqxwwxglawjvneegoxztrcyjqlduczzhgdlesnaeyialxfhtcgwkxjcdsllpqwurenryothdqzdbjmppjyvwzxobkvlrxjytmpklararqdqjjnblxaliqhjvtbzysfkbhroccnlwnslpsvkarenxfezocpdocgamvufzcfjkxijwybwgbfmnnwuuunsoupaxbylxggremxxakntirsqjwkyxkldqokrlwevrvoovoekhesvxmbnycclrdhrzzbovalhtnzdhfuyatdgeyazstiovogkiuuvsjvvofvrfwyoxydkgkvhporcxccrlcecgqakknogwyemwcfmokuflsskyevbdkmmumftzcpdonagopprxcmwwuarqxbxglrnprstubwfjmxpwdsribxcglhhzthhajimjawanewsqmwifzndqwojclkdilkisapeegpeixshskpfdnsbmfjiojelllsvuquupkwvnkgfdwreabvhyswnsnsdofccebjqmawlkqbzcrxqcvargeqvruhgypqcfbltnhswzjbjayqglgsyttnvpxrjbbotzcmoscbykzxoqoqkooycfiviewtmpyzzpicglhsydafzdzresxjeqhahsukeprzooumbltzxhmqktoypcjenuqqlkpwtvyscfcxcodnokzxpcjlimqmeltiipawblteiyaftlvefhrglstuwupkfvjzhrlvejljfahcenhnsqmmcfpnbtwrkukzncabvgyvvfqhsairahkulbejckkoapagatvkhceqswlpzijcwddrooijdcircayscwmordpckluyryrguednmhzleeklgggqujqeobgesjdbpuueenraljjecjxssdosskkbhrnykrfvumazfcjalcttxewlxiwtsojrmeakgzkwympgkdrshbiaamlwwwvacewcjgaruzmcpblpgqdyykxjyybhwwgowlcsliiitgffqdfprvrrf";
    cout << s.lastSubstring(s2) << endl;
    return 0;
}
