
#include "who-tables.h"

#ifdef __AVR__
  #include <turbo/turbo.h>
#endif

/**
 * @name who_tables:
 *   Do not reorder; the order of entries is significant.
 */
#ifdef __AVR__
  const PROGMEM polynomial_table_entry_t who_tables[] = {
#else
  const polynomial_table_entry_t who_tables[] = {
#endif

  { { T_WFA, G_FEMALE, -4 },
    { { 0, 1856 }, {
      1.6759740922389,
      0.0232748769615228,
      -0.0000605260015320574,
      0.0000000953741098397645,
      -0.0000000000786128884004803,
      0.0000000000000320554496154721,
      -0.000000000000000005111300107195 } } },

  { { T_WFA, G_FEMALE, -3 },
    { { 0, 1856 }, {
      2.04262799896605,
      0.0255468879087175,
      -0.0000660253149589174,
      0.000000103794194578587,
      -0.0000000000852564110008134,
      0.0000000000000346892190952363,
      -0.000000000000000005525821478003 } } },

  { { T_WFA, G_FEMALE, -2 },
    { { 0, 1856 }, {
      2.40937706025943,
      0.027817422172177,
      -0.0000715167834046682,
      0.000000112196486314227,
      -0.0000000000918809386950278,
      0.0000000000000373135214846181,
      -0.000000000000000005938566298913 } } },

  { { T_WFA, G_FEMALE, -1 },
    { { 0, 1856 }, {
      2.82065510730536,
      0.0304051553669069,
      -0.0000775136318815761,
      0.000000121181667146232,
      -0.0000000000988523665940321,
      0.000000000000040052378432479,
      -0.000000000000000006368047625151 } } },

  { { T_WFA, G_FEMALE, 0 },
    { { 0, 1856 }, {
      3.27998347288303,
      0.0333677895415576,
      -0.0000840363426566348,
      0.000000130703201989789,
      -0.00000000010609235902241,
      0.0000000000000428684976510968,
      -0.000000000000000006808390867917 } } },

  { { T_WFA, G_FEMALE, 1 },
    { { 0, 1856 }, {
      3.79065781352256,
      0.0367739222863293,
      -0.0000910827920019841,
      0.000000140651093808244,
      -0.000000000113458875542928,
      0.0000000000000456981388433004,
      -0.000000000000000007249673146068 } } },

  { { T_WFA, G_FEMALE, 2 },
    { { 0, 1856 }, {
      4.35644160914671,
      0.0406940889538419,
      -0.0000985812031295552,
      0.000000150767349082689,
      -0.000000000120669654247953,
      0.0000000000000484186086518188,
      -0.000000000000000007672654348718 } } },

  { { T_WFA, G_FEMALE, 3 },
    { { 0, 1856 }, {
      4.98095695048687,
      0.0452130810836024,
      -0.000106434771969255,
      0.000000160755120746231,
      -0.000000000127424998529622,
      0.0000000000000509125076554492,
      -0.000000000000000008061139504996 } } },

  { { T_WFA, G_FEMALE, 4 },
    { { 0, 1856 }, {
      5.605389478,
      0.04973236689,
      -0.0001142852871,
      0.0000001707311569,
      -0.0000000001341655417,
      0.0000000000000533985138265789,
      -0.000000000000000008448099402122 } } },

  { { T_WFA, G_MALE, -4 },
    { { 0, 1856 }, {
      1.75568796175503,
      0.0274048138483067,
      -0.0000717950495201514,
      0.000000109564717287562,
      -0.0000000000884999016395773,
      0.0000000000000357685513460902,
      -0.000000000000000005694144563946 } } },

  { { T_WFA, G_MALE, -3 },
    { { 0, 1856 }, {
      2.14643925067139,
      0.0298481973156299,
      -0.0000780490128158284,
      0.000000119849724062628,
      -0.0000000000971791061131559,
      0.0000000000000393751908393966,
      -0.000000000000000006278212892271 } } },

  { { T_WFA, G_MALE, -2 },
    { { 0, 1856 }, {
      2.53726763700615,
      0.0322896234915788,
      -0.0000842932859281831,
      0.000000130114012955422,
      -0.000000000105836725876533,
      0.0000000000000429710865142741,
      -0.000000000000000006860237938525 } } },

  { { T_WFA, G_MALE, -1 },
    { { 0, 1856 }, {
      2.97562825426212,
      0.0349035691983772,
      -0.0000908744264638273,
      0.000000141037247867494,
      -0.000000000115094606631572,
      0.0000000000000468283237953725,
      -0.000000000000000007485691860104 } } },

  { { T_WFA, G_MALE, 0 },
    { { 0, 1856 }, {
      3.46464181804913,
      0.0377144450784499,
      -0.0000978430583606915,
      0.000000152723519148898,
      -0.000000000125042676583028,
      0.0000000000000509839486045949,
      -0.000000000000000008160344390615 } } },

  { { T_WFA, G_MALE, 1 },
    { { 0, 1856 }, {
      4.00814497041574,
      0.0407401145607764,
      -0.000105224044548713,
      0.000000165249095280748,
      -0.000000000135758183245961,
      0.0000000000000554740782717157,
      -0.000000000000000008890412450108 } } },

  { { T_WFA, G_MALE, 2 },
    { { 0, 1856 }, {
      4.60955812739121,
      0.0440072758561882,
      -0.000113066986552113,
      0.000000178731207813032,
      -0.000000000147348388734362,
      0.0000000000000603454736960249,
      -0.00000000000000000968351205396 } } },

  { { T_WFA, G_MALE, 3 },
    { { 0, 1856 }, {
      5.27256258542911,
      0.0475437844721682,
      -0.00012142074716337,
      0.000000193290478164854,
      -0.00000000015992257050687,
      0.0000000000000656458348290534,
      -0.00000000000000001054739926583 } } },

  { { T_WFA, G_MALE, 4 },
    { { 0, 1856 }, {
      5.935592864,
      0.05108072303,
      -0.0001297759199,
      0.0000002078493766,
      -0.0000000001724929626,
      0.0000000000000709429152339052,
      -0.000000000000000011410458738094 } } },

  { { T_LHFA, G_FEMALE, -4 },
    { { 0, 1856 }, {
      42.9824527935998,
      0.101784517046781,
      -0.000191435030874487,
      0.000000250282267903745,
      -0.000000000185945354349204,
      0.0000000000000716585723378918,
      -0.000000000000000011101556840696 } } },

  { { T_LHFA, G_FEMALE, -3 },
    { { 0, 1856 }, {
      44.8699508991849,
      0.104224109646566,
      -0.00019451386960867,
      0.000000256514296900767,
      -0.000000000192042381353026,
      0.0000000000000744105425762812,
      -0.0000000000000000115696354492 } } },

  { { T_LHFA, G_FEMALE, -2 },
    { { 0, 1856 }, {
      46.7573203516367,
      0.106665336310016,
      -0.000197600984026991,
      0.000000262763999600568,
      -0.000000000198157134953948,
      0.0000000000000771707618071549,
      -0.000000000000000012039145442459 } } },

  { { T_LHFA, G_FEMALE, -1 },
    { { 0, 1856 }, {
      48.6449206002872,
      0.109103209915702,
      -0.000200674238655552,
      0.0000002689885625351,
      -0.000000000204249356719531,
      0.0000000000000799212399374507,
      -0.00000000000000001250703851209 } } },

  { { T_LHFA, G_FEMALE, 0 },
    { { 0, 1856 }, {
      50.532493751467,
      0.111542169763197,
      -0.000203752412549107,
      0.000000275222411839915,
      -0.000000000210350103526139,
      0.0000000000000826754765746179,
      -0.00000000000000001297556988081 } } },

  { { T_LHFA, G_FEMALE, 1 },
    { { 0, 1856 }, {
      52.4199805189855,
      0.113981091700225,
      -0.00020682798954752,
      0.000000281448858371891,
      -0.000000000216442864221518,
      0.0000000000000854259459467254,
      -0.000000000000000013443445120821 } } },

  { { T_LHFA, G_FEMALE, 2 },
    { { 0, 1856 }, {
      54.3074571879697,
      0.116420680234114,
      -0.000209906842808749,
      0.000000287681126989736,
      -0.000000000222540081333414,
      0.000000000000088177874399259,
      -0.000000000000000013911480685237 } } },

  { { T_LHFA, G_FEMALE, 3 },
    { { 0, 1856 }, {
      56.194988541567,
      0.118859602213888,
      -0.000212984053341359,
      0.000000293912234126947,
      -0.000000000228638008401222,
      0.0000000000000909308977709171,
      -0.000000000000000014379824413205 } } },

  { { T_LHFA, G_FEMALE, 4 },
    { { 0, 1856 }, {
      58.08239913,
      0.1213003043,
      -0.0002160684675,
      0.0000003001567764,
      -0.000000000234748289,
      0.0000000000000936893677927279,
      -0.000000000000000014849091635821 } } },

  { { T_LHFA, G_MALE, -4 },
    { { 0, 1856 }, {
      43.6548051297723,
      0.117946363217925,
      -0.000240883516731571,
      0.000000320956010664564,
      -0.000000000240657545974576,
      0.0000000000000933582019581462,
      -0.000000000000000014523469058226 } } },

  { { T_LHFA, G_MALE, -3 },
    { { 0, 1856 }, {
      45.5631203461962,
      0.11948243409779,
      -0.000243788399920675,
      0.000000330147535622383,
      -0.000000000250714486619967,
      0.0000000000000980356914419944,
      -0.000000000000000015319488368716 } } },

  { { T_LHFA, G_MALE, -2 },
    { { 0, 1856 }, {
      46.098,
      0.138764636681458,
      -0.000318345309411328,
      0.000000467918378207338,
      -0.000000000374985760606179,
      0.000000000000151903236607635,
      -0.000000000000000024312205030644 } } },

  { { T_LHFA, G_MALE, -1 },
    { { 0, 1856 }, {
      49.3795705576777,
      0.122557099295591,
      -0.000249604906898071,
      0.000000348537724112474,
      -0.000000000270831698620478,
      0.000000000000107391246107545,
      -0.000000000000000016911531101365 } } },

  { { T_LHFA, G_MALE, 0 },
    { { 0, 1856 }, {
      51.2877857426356,
      0.124094731211699,
      -0.000252515332437753,
      0.000000357738157291676,
      -0.000000000280895954045889,
      0.000000000000112071733009383,
      -0.000000000000000017708039259038 } } },

  { { T_LHFA, G_MALE, 1 },
    { { 0, 1856 }, {
      53.1960744684038,
      0.125631312858786,
      -0.000255421476037299,
      0.000000366930370261642,
      -0.000000000290952241899928,
      0.000000000000116748481690127,
      -0.000000000000000018503871255528 } } },

  { { T_LHFA, G_MALE, 2 },
    { { 0, 1856 }, {
      55.1042853633699,
      0.127169388761104,
      -0.000258333929473054,
      0.000000376134296570241,
      -0.00000000030101942429851,
      0.000000000000121430112357759,
      -0.000000000000000019300539045326 } } },

  { { T_LHFA, G_MALE, 3 },
    { { 0, 1856 }, {
      57.012460455735,
      0.128706320232595,
      -0.000261238735372871,
      0.00000038532101145905,
      -0.000000000311069148555226,
      0.000000000000126103605920665,
      -0.000000000000000020095791361883 } } },

  { { T_LHFA, G_MALE, 4 },
    { { 0, 1856 }, {
      58.92075385,
      0.1302441008,
      -0.000264151383,
      0.0000003945264038,
      -0.0000000003211380556,
      0.00000000000013078611792277,
      -0.000000000000000020892635370232 } } },

  { { T_WFH, G_FEMALE, -4 },
    { { 0, 757 }, {
      1.73430100269252,
      0.0084507047849911,
      0.00010428545256147,
      -0.000000522692819332482,
      0.00000000118147045413079,
      -0.00000000000124164437380492,
      0.000000000000000506093944086068 } } },

  { { T_WFH, G_FEMALE, -3 },
    { { 0, 757 }, {
      1.899931119955,
      0.00918029939316511,
      0.000115801475022437,
      -0.000000580746448666791,
      0.00000000130859484332542,
      -0.00000000000136820129101326,
      0.000000000000000555027832628011 } } },

  { { T_WFH, G_FEMALE, -2 },
    { { 0, 757 }, {
      2.06557704475563,
      0.00990920142271534,
      0.00012732234199575,
      -0.000000638826333027032,
      0.00000000143577860847255,
      -0.00000000000149480162114831,
      0.000000000000000603963349397443 } } },

  { { T_WFH, G_FEMALE, -1 },
    { { 0, 757 }, {
      2.2519675570511,
      0.0107188627127925,
      0.00014046092570652,
      -0.000000705057041666679,
      0.00000000158037676955408,
      -0.00000000000163804991497597,
      0.00000000000000065909586185693 } } },

  { { T_WFH, G_FEMALE, 0 },
    { { 0, 757 }, {
      2.46283845576545,
      0.0116080038878863,
      0.000155662123351163,
      -0.000000781637627150777,
      0.00000000174709125026198,
      -0.00000000000180246791786002,
      0.000000000000000722099389850922 } } },

  { { T_WFH, G_FEMALE, 1 },
    { { 0, 757 }, {
      2.70104954892304,
      0.0126290631310439,
      0.000172931327337977,
      -0.000000868937032494355,
      0.00000000193679699085321,
      -0.00000000000198869644437107,
      0.000000000000000793159151345333 } } },

  { { T_WFH, G_FEMALE, 2 },
    { { 0, 757 }, {
      2.97282990521489,
      0.0137672536652644,
      0.000192968332086707,
      -0.000000970103685382639,
      0.00000000215573475162347,
      -0.00000000000220228792322154,
      0.000000000000000874186287019774 } } },

  { { T_WFH, G_FEMALE, 3 },
    { { 0, 757 }, {
      3.28390223058523,
      0.0150567887530997,
      0.000216232572569197,
      -0.00000108768132517367,
      0.00000000240940563355808,
      -0.00000000000244838421159003,
      0.000000000000000967064018527976 } } },

  { { T_WFH, G_FEMALE, 4 },
    { { 0, 757 }, {
      3.59512334724423,
      0.0163370117784325,
      0.000239613709183573,
      -0.00000120587578628095,
      0.00000000266464071890359,
      -0.00000000000269635564863285,
      0.00000000000000106079292356523 } } },

  { { T_WFH, G_MALE, -4 },
    { { 0, 757 }, {
      1.75395869270142,
      0.00488903232349003,
      0.000171539975411861,
      -0.00000085862032095374,
      0.00000000195538532176028,
      -0.00000000000208876078069782,
      0.000000000000000857845655611102 } } },

  { { T_WFH, G_MALE, -3 },
    { { 0, 757 }, {
      1.92097529830062,
      0.00566801804370698,
      0.000178636856816183,
      -0.000000882063932353128,
      0.00000000197738954943742,
      -0.00000000000207827427468867,
      0.000000000000000842226771443528 } } },

  { { T_WFH, G_MALE, -2 },
    { { 0, 757 }, {
      2.08791353562265,
      0.00644734267689273,
      0.000185736710708539,
      -0.000000905551296823126,
      0.00000000199956367360078,
      -0.00000000000206804917209971,
      0.000000000000000826748267425626 } } },

  { { T_WFH, G_MALE, -1 },
    { { 0, 757 }, {
      2.27518397346648,
      0.00734541386827914,
      0.000192877934122038,
      -0.000000926691638730714,
      0.00000000200976910764636,
      -0.00000000000203790525336397,
      0.000000000000000800758720582491 } } },

  { { T_WFH, G_MALE, 0 },
    { { 0, 757 }, {
      2.48608952845098,
      0.00838944351380633,
      0.000199810115486088,
      -0.000000943497867278431,
      0.00000000200181996239807,
      -0.00000000000197959309483098,
      0.000000000000000760382183498471 } } },

  { { T_WFH, G_MALE, 1 },
    { { 0, 757 }, {
      2.72426578086743,
      0.00961117002839273,
      0.000206361911338604,
      -0.000000954527142105199,
      0.00000000197078732288658,
      -0.00000000000188604040957188,
      0.000000000000000702131553465027 } } },

  { { T_WFH, G_MALE, 2 },
    { { 0, 757 }, {
      2.99452225339337,
      0.0110410138836414,
      0.000212332665785908,
      -0.000000957874256551916,
      0.00000000191012004439406,
      -0.00000000000174795120522582,
      0.000000000000000621482081057919 } } },

  { { T_WFH, G_MALE, 3 },
    { { 0, 757 }, {
      3.30257079352305,
      0.0127167068467315,
      0.000217446728665749,
      -0.000000951038889446254,
      0.0000000018114200281351,
      -0.00000000000155358087986466,
      0.000000000000000512772095022015 } } },

  { { T_WFH, G_MALE, 4 },
    { { 0, 757 }, {
      3.610506985,
      0.01439661482,
      0.0002225060336,
      -0.0000009438922624,
      0.000000001711893689,
      -0.00000000000135820353042622,
      0.000000000000000403607995877107 } } },

  POLYNOMIAL_TABLE_END
};

