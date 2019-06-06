

//##############// variables globales de ce fichier

static keyofgame keyp; // key for playing (boulean pour utiliser plusieurs touches en meme temps)

static char tomber=0;

#define vitesse_y 1 //vitesse de deplacement dans l'axe des y

#define vitesse_x 1 //vitesse de deplacement dans l'axe des x

int debut_saut=-1;
int temps_saut;
int decalage_x=0;


typedef struct bloc{
	POINT p;
	POINT p_h;
	POINT milieu_haut;
	int id;
	int contenu;
}bloc;


//##############//


void bouleankey(){
	SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		
		if (event.type == SDL_QUIT) exit(0);
		
		if (event.type == SDL_KEYDOWN) { 
			//pas de switch car un switch s'utilise pour des constantes et non des variables sinon erreur : "case label does not reduce to an integer constant"
			if(event.key.keysym.sym==SDLK_ESCAPE)stop=1;
			if(event.key.keysym.sym==keyc.left)keyp.left=1;
			if(event.key.keysym.sym==keyc.right)keyp.right=1;
			if(event.key.keysym.sym==keyc.up)keyp.up=1;
			if(event.key.keysym.sym==keyc.down)keyp.down=1;
			if(event.key.keysym.sym==keyc.jump)keyp.jump=1;
			if(event.key.keysym.sym==keyc.run)keyp.run=1;
			if(event.key.keysym.sym==SDLK_RETURN)wait_enter();
		}
		if (event.type == SDL_KEYUP) {
			if(event.key.keysym.sym==keyc.left)keyp.left=0;
			if(event.key.keysym.sym==keyc.right)keyp.right=0;
			if(event.key.keysym.sym==keyc.up)keyp.up=0;
			if(event.key.keysym.sym==keyc.down)keyp.down=0;
			if(event.key.keysym.sym==keyc.jump)keyp.jump=0;
			if(event.key.keysym.sym==keyc.run)keyp.run=0;
		}
	}
}

void delete_block(bloc *b){
	b->id=0;
	b->p.x=cases*-10;
	b->p.y=cases*-10;
}

void calcul_p(bloc *b, int x, int y){
	b->p.x=cases*x;
	b->p.y=cases*y;
}

void init_game(int niv,bloc *mario, bloc block[100][10]){
	int t[1000],i,j,k=0;
	
	for(i=0;i<100;i++){
		for(j=0;j<10;j++){
			delete_block(&block[i][j]);
		}
	}
	
	char chaine[25]; sprintf(chaine,"les niveaux/niv%d.mario",niv);
	charge_level=fopen(chaine,"r");
	int b=fscanf(charge_level,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ",&t[0],&t[1],&t[2],&t[3],&t[4],&t[5],&t[6],&t[7],&t[8],&t[9],&t[10],&t[11],&t[12],&t[13],&t[14],&t[15],&t[16],&t[17],&t[18],&t[19],&t[20],&t[21],&t[22],&t[23],&t[24],&t[25],&t[26],&t[27],&t[28],&t[29],&t[30],&t[31],&t[32],&t[33],&t[34],&t[35],&t[36],&t[37],&t[38],&t[39],&t[40],&t[41],&t[42],&t[43],&t[44],&t[45],&t[46],&t[47],&t[48],&t[49],&t[50],&t[51],&t[52],&t[53],&t[54],&t[55],&t[56],&t[57],&t[58],&t[59],&t[60],&t[61],&t[62],&t[63],&t[64],&t[65],&t[66],&t[67],&t[68],&t[69],&t[70],&t[71],&t[72],&t[73],&t[74],&t[75],&t[76],&t[77],&t[78],&t[79],&t[80],&t[81],&t[82],&t[83],&t[84],&t[85],&t[86],&t[87],&t[88],&t[89],&t[90],&t[91],&t[92],&t[93],&t[94],&t[95],&t[96],&t[97],&t[98],&t[99],&t[100],&t[101],&t[102],&t[103],&t[104],&t[105],&t[106],&t[107],&t[108],&t[109],&t[110],&t[111],&t[112],&t[113],&t[114],&t[115],&t[116],&t[117],&t[118],&t[119],&t[120],&t[121],&t[122],&t[123],&t[124],&t[125],&t[126],&t[127],&t[128],&t[129],&t[130],&t[131],&t[132],&t[133],&t[134],&t[135],&t[136],&t[137],&t[138],&t[139],&t[140],&t[141],&t[142],&t[143],&t[144],&t[145],&t[146],&t[147],&t[148],&t[149],&t[150],&t[151],&t[152],&t[153],&t[154],&t[155],&t[156],&t[157],&t[158],&t[159],&t[160],&t[161],&t[162],&t[163],&t[164],&t[165],&t[166],&t[167],&t[168],&t[169],&t[170],&t[171],&t[172],&t[173],&t[174],&t[175],&t[176],&t[177],&t[178],&t[179],&t[180],&t[181],&t[182],&t[183],&t[184],&t[185],&t[186],&t[187],&t[188],&t[189],&t[190],&t[191],&t[192],&t[193],&t[194],&t[195],&t[196],&t[197],&t[198],&t[199],&t[200],&t[201],&t[202],&t[203],&t[204],&t[205],&t[206],&t[207],&t[208],&t[209],&t[210],&t[211],&t[212],&t[213],&t[214],&t[215],&t[216],&t[217],&t[218],&t[219],&t[220],&t[221],&t[222],&t[223],&t[224],&t[225],&t[226],&t[227],&t[228],&t[229],&t[230],&t[231],&t[232],&t[233],&t[234],&t[235],&t[236],&t[237],&t[238],&t[239],&t[240],&t[241],&t[242],&t[243],&t[244],&t[245],&t[246],&t[247],&t[248],&t[249],&t[250],&t[251],&t[252],&t[253],&t[254],&t[255],&t[256],&t[257],&t[258],&t[259],&t[260],&t[261],&t[262],&t[263],&t[264],&t[265],&t[266],&t[267],&t[268],&t[269],&t[270],&t[271],&t[272],&t[273],&t[274],&t[275],&t[276],&t[277],&t[278],&t[279],&t[280],&t[281],&t[282],&t[283],&t[284],&t[285],&t[286],&t[287],&t[288],&t[289],&t[290],&t[291],&t[292],&t[293],&t[294],&t[295],&t[296],&t[297],&t[298],&t[299],&t[300],&t[301],&t[302],&t[303],&t[304],&t[305],&t[306],&t[307],&t[308],&t[309],&t[310],&t[311],&t[312],&t[313],&t[314],&t[315],&t[316],&t[317],&t[318],&t[319],&t[320],&t[321],&t[322],&t[323],&t[324],&t[325],&t[326],&t[327],&t[328],&t[329],&t[330],&t[331],&t[332],&t[333],&t[334],&t[335],&t[336],&t[337],&t[338],&t[339],&t[340],&t[341],&t[342],&t[343],&t[344],&t[345],&t[346],&t[347],&t[348],&t[349],&t[350],&t[351],&t[352],&t[353],&t[354],&t[355],&t[356],&t[357],&t[358],&t[359],&t[360],&t[361],&t[362],&t[363],&t[364],&t[365],&t[366],&t[367],&t[368],&t[369],&t[370],&t[371],&t[372],&t[373],&t[374],&t[375],&t[376],&t[377],&t[378],&t[379],&t[380],&t[381],&t[382],&t[383],&t[384],&t[385],&t[386],&t[387],&t[388],&t[389],&t[390],&t[391],&t[392],&t[393],&t[394],&t[395],&t[396],&t[397],&t[398],&t[399],&t[400],&t[401],&t[402],&t[403],&t[404],&t[405],&t[406],&t[407],&t[408],&t[409],&t[410],&t[411],&t[412],&t[413],&t[414],&t[415],&t[416],&t[417],&t[418],&t[419],&t[420],&t[421],&t[422],&t[423],&t[424],&t[425],&t[426],&t[427],&t[428],&t[429],&t[430],&t[431],&t[432],&t[433],&t[434],&t[435],&t[436],&t[437],&t[438],&t[439],&t[440],&t[441],&t[442],&t[443],&t[444],&t[445],&t[446],&t[447],&t[448],&t[449],&t[450],&t[451],&t[452],&t[453],&t[454],&t[455],&t[456],&t[457],&t[458],&t[459],&t[460],&t[461],&t[462],&t[463],&t[464],&t[465],&t[466],&t[467],&t[468],&t[469],&t[470],&t[471],&t[472],&t[473],&t[474],&t[475],&t[476],&t[477],&t[478],&t[479],&t[480],&t[481],&t[482],&t[483],&t[484],&t[485],&t[486],&t[487],&t[488],&t[489],&t[490],&t[491],&t[492],&t[493],&t[494],&t[495],&t[496],&t[497],&t[498],&t[499],&t[500],&t[501],&t[502],&t[503],&t[504],&t[505],&t[506],&t[507],&t[508],&t[509],&t[510],&t[511],&t[512],&t[513],&t[514],&t[515],&t[516],&t[517],&t[518],&t[519],&t[520],&t[521],&t[522],&t[523],&t[524],&t[525],&t[526],&t[527],&t[528],&t[529],&t[530],&t[531],&t[532],&t[533],&t[534],&t[535],&t[536],&t[537],&t[538],&t[539],&t[540],&t[541],&t[542],&t[543],&t[544],&t[545],&t[546],&t[547],&t[548],&t[549],&t[550],&t[551],&t[552],&t[553],&t[554],&t[555],&t[556],&t[557],&t[558],&t[559],&t[560],&t[561],&t[562],&t[563],&t[564],&t[565],&t[566],&t[567],&t[568],&t[569],&t[570],&t[571],&t[572],&t[573],&t[574],&t[575],&t[576],&t[577],&t[578],&t[579],&t[580],&t[581],&t[582],&t[583],&t[584],&t[585],&t[586],&t[587],&t[588],&t[589],&t[590],&t[591],&t[592],&t[593],&t[594],&t[595],&t[596],&t[597],&t[598],&t[599],&t[600],&t[601],&t[602],&t[603],&t[604],&t[605],&t[606],&t[607],&t[608],&t[609],&t[610],&t[611],&t[612],&t[613],&t[614],&t[615],&t[616],&t[617],&t[618],&t[619],&t[620],&t[621],&t[622],&t[623],&t[624],&t[625],&t[626],&t[627],&t[628],&t[629],&t[630],&t[631],&t[632],&t[633],&t[634],&t[635],&t[636],&t[637],&t[638],&t[639],&t[640],&t[641],&t[642],&t[643],&t[644],&t[645],&t[646],&t[647],&t[648],&t[649],&t[650],&t[651],&t[652],&t[653],&t[654],&t[655],&t[656],&t[657],&t[658],&t[659],&t[660],&t[661],&t[662],&t[663],&t[664],&t[665],&t[666],&t[667],&t[668],&t[669],&t[670],&t[671],&t[672],&t[673],&t[674],&t[675],&t[676],&t[677],&t[678],&t[679],&t[680],&t[681],&t[682],&t[683],&t[684],&t[685],&t[686],&t[687],&t[688],&t[689],&t[690],&t[691],&t[692],&t[693],&t[694],&t[695],&t[696],&t[697],&t[698],&t[699],&t[700],&t[701],&t[702],&t[703],&t[704],&t[705],&t[706],&t[707],&t[708],&t[709],&t[710],&t[711],&t[712],&t[713],&t[714],&t[715],&t[716],&t[717],&t[718],&t[719],&t[720],&t[721],&t[722],&t[723],&t[724],&t[725],&t[726],&t[727],&t[728],&t[729],&t[730],&t[731],&t[732],&t[733],&t[734],&t[735],&t[736],&t[737],&t[738],&t[739],&t[740],&t[741],&t[742],&t[743],&t[744],&t[745],&t[746],&t[747],&t[748],&t[749],&t[750],&t[751],&t[752],&t[753],&t[754],&t[755],&t[756],&t[757],&t[758],&t[759],&t[760],&t[761],&t[762],&t[763],&t[764],&t[765],&t[766],&t[767],&t[768],&t[769],&t[770],&t[771],&t[772],&t[773],&t[774],&t[775],&t[776],&t[777],&t[778],&t[779],&t[780],&t[781],&t[782],&t[783],&t[784],&t[785],&t[786],&t[787],&t[788],&t[789],&t[790],&t[791],&t[792],&t[793],&t[794],&t[795],&t[796],&t[797],&t[798],&t[799],&t[800],&t[801],&t[802],&t[803],&t[804],&t[805],&t[806],&t[807],&t[808],&t[809],&t[810],&t[811],&t[812],&t[813],&t[814],&t[815],&t[816],&t[817],&t[818],&t[819],&t[820],&t[821],&t[822],&t[823],&t[824],&t[825],&t[826],&t[827],&t[828],&t[829],&t[830],&t[831],&t[832],&t[833],&t[834],&t[835],&t[836],&t[837],&t[838],&t[839],&t[840],&t[841],&t[842],&t[843],&t[844],&t[845],&t[846],&t[847],&t[848],&t[849],&t[850],&t[851],&t[852],&t[853],&t[854],&t[855],&t[856],&t[857],&t[858],&t[859],&t[860],&t[861],&t[862],&t[863],&t[864],&t[865],&t[866],&t[867],&t[868],&t[869],&t[870],&t[871],&t[872],&t[873],&t[874],&t[875],&t[876],&t[877],&t[878],&t[879],&t[880],&t[881],&t[882],&t[883],&t[884],&t[885],&t[886],&t[887],&t[888],&t[889],&t[890],&t[891],&t[892],&t[893],&t[894],&t[895],&t[896],&t[897],&t[898],&t[899],&t[900],&t[901],&t[902],&t[903],&t[904],&t[905],&t[906],&t[907],&t[908],&t[909],&t[910],&t[911],&t[912],&t[913],&t[914],&t[915],&t[916],&t[917],&t[918],&t[919],&t[920],&t[921],&t[922],&t[923],&t[924],&t[925],&t[926],&t[927],&t[928],&t[929],&t[930],&t[931],&t[932],&t[933],&t[934],&t[935],&t[936],&t[937],&t[938],&t[939],&t[940],&t[941],&t[942],&t[943],&t[944],&t[945],&t[946],&t[947],&t[948],&t[949],&t[950],&t[951],&t[952],&t[953],&t[954],&t[955],&t[956],&t[957],&t[958],&t[959],&t[960],&t[961],&t[962],&t[963],&t[964],&t[965],&t[966],&t[967],&t[968],&t[969],&t[970],&t[971],&t[972],&t[973],&t[974],&t[975],&t[976],&t[977],&t[978],&t[979],&t[980],&t[981],&t[982],&t[983],&t[984],&t[985],&t[986],&t[987],&t[988],&t[989],&t[990],&t[991],&t[992],&t[993],&t[994],&t[995],&t[996],&t[997],&t[998],&t[999]);
	printf("%d\n",b);
	
	for(i=0;i<100;i++){
		for(j=0;j<10;j++){
			block[i][j].id=t[k];
			calcul_p(&block[i][j],i,j);
			if(t[k]==id_mario){
				delete_block(&block[i][j]);
				calcul_p(mario,i,j);
			}
			k++;
		}
	}
	fclose(charge_level);
}

void affiche_block(bloc mario, bloc block [100][10]){
	for(i=(decalage_x/cases);i<(decalage_x/cases)+15;i++){
		for(j=0;j<10;j++){
			if(block[i][j].id==id_background)draw_paint(background,block[i][j].p,5);
			if(block[i][j].id==id_brick)draw_paint(brick,block[i][j].p,5);
			//if(block[i][j].id=id_)draw_paint(,block[i][j].p,5);
		}
	}
	if( keyp.jump || tomber ) draw_paint(mariosaut,mario.p,5);
	else draw_paint(mariopose,mario.p,5);
}

void deplacement(bloc *mario){
	
	if(tomber){//la chute, si tomber=1 on tombe jusqua toucher le sol
		mario->p.y-=vitesse_y;
	}
	
	if(keyp.jump==1 && !tomber){ // sauter si on est au sol
		mario->p.y+=vitesse_y;
	}
	
	if(keyp.left==1)mario->p.x-=vitesse_x;
	if(keyp.right==1)mario->p.x+=vitesse_x;
	
}

void collision(bloc *mario,bloc block[100][10]){
	
	//pour ne pas dépasser le bord de gauche
	if(mario->p.x<0)mario->p.x+=vitesse_x;
	
	//pour faire tourner la map
	if(mario->p_h.x>cases*8){
		mario->p.x-=vitesse_x;
		if( (decalage_x/cases)+14<100 )decalage_x+=vitesse_x;
		for(i=0;i<100;i++){
			for(j=0;j<10;j++){
				block[i][j].p.x-=2;
			}
		}
	}
	
	for(i=(decalage_x/cases);i<(decalage_x/cases)+15;i++){
		for(j=0;j<10;j++){
			
			//collision en tombant
			
			if(keyp.jump==0){
				if(mario->p.y-vitesse_y<=block[i][j].p_h.y){ 
					if(( mario->p_h.x>=block[i][j].p.x && mario->p_h.x<=block[i][j].p_h.x ) || (mario->p.x>=block[i][j].p.x && mario->p.x<=block[i][j].p_h.x) ){
						tomber=0;
					}
				}
				else tomber=1;
			}
			
			//collision en allant a droite
			
			
			//collision en allant a gauche
			
			
			//collision en sautant
			
		}
	}
}

void replace_haut(bloc *mario, bloc block[100][10]){
	int i;
	
	for(i=(decalage_x/cases);i<(decalage_x/cases)+15;i++){
		for(j=0;j<10;j++){
			block[i][j].p_h.x=block[i][j].p.x+cases-1;
			block[i][j].p_h.y=block[i][j].p.y+cases-1;
		}
	}
	
	mario->p_h.x=mario->p.x+cases-16;
	mario->p_h.y=mario->p.y+cases-1-8;
	mario->milieu_haut.y=(mario->p_h.y+mario->p.y)/2;
	mario->milieu_haut.x=(mario->p.x+mario->p_h.x)/2;
}

void playing(){
	cases=16*5;
	init_graphics(cases*14,cases*10);
	SDL_WM_SetCaption("Super Mario Bros PC",NULL);
	
	keyp.up=keyp.down=keyp.left=keyp.right=keyp.run=keyp.jump=0;
	bloc block[100][10];
	bloc mario;
	affiche_auto_off();
	
	//int a=num_molette();
	//init_game(a,&mario,block);
	init_game(1,&mario,block);
	
	
	while(!stop){
		fill_screen(ciel);
		
		bouleankey();
		deplacement(&mario);
		
		replace_haut(&mario,block);
		collision(&mario,block);
		replace_haut(&mario,block);
		
		affiche_block(mario,block);
		affiche_all();
	}

	//revenir au menu
	stop=0;
	init_graphics(600,600);
	SDL_WM_SetCaption("Mario Bros",NULL);
}
