#include <stdio.h>
#include <string.h>
struct player
{
	char player_id[50];
	int previous_total_score;
	int previous_avg;
	int previous_total_wickets;
	int previous_wicket_avg;
	int total_runs_in_last_five_matches;
	int total_wickets_in_last_five_matches;
	int century;
	int present_match_score;
	int present_match_wicket;
	char player_role[50];
	char outnot_out[50];
	int MoM;
};
struct team
{
	char team_name[50];
	struct player p[15];
	char grp;
	int match_count;
	int points;
};
struct match_played
{
	char match_id[50];
	char team1[50];
	char team2[50];
	int higest_run;
	char man_of_the_match[50];
	int wicket_taken_by_pacer;
	char match_result[50];
};

struct bestbatter
{
	char player_id[50];
	int previous_total_score;
};

struct bestbowler
{
	char player_id[50];
	int previous_total_wickets;
};


//Merge Sort
	void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int ans[r-l+1];
         int i=l;
         int j=m+1;
         int k=0;
         while(i<=m && j<=r)
         {
             if(arr[i]<arr[j])
             {
                 ans[k++]=arr[i++];
             }
             else
             {
                 ans[k++]=arr[j++];
             }
         }
         while(i<=m)
         {
             ans[k++]=arr[i++];
         }
         while(j<=r)
         {
             ans[k++]=arr[j++];
         }
         for( i=0;i<r-l+1;i++)
         {
             arr[l+i]=ans[i];
         }
    }
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r)
        {
            int m=l+(r-l)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
    
    
    //Merge sort for strings
    void mergeStr(char arr[][50], int l, int m, int r)
    {
         // Your code here
         char ans[r-l+1][50];
         int i=l;
         int j=m+1;
         int k=0;
         while(i<=m && j<=r)
         {
             if(strcmp(arr[i],arr[j])<0)
             {
                 strcpy(ans[k],arr[i]);
                 k++;
                 i++;
             }
             else
             {
                 strcpy(ans[k],arr[j]);
                 k++;
                 j++;
             }
         }
         while(i<=m)
         {
            strcpy(ans[k],arr[i]);
            k++;
            i++;
         }
         while(j<=r)
         {
             strcpy(ans[k],arr[j]);
            	k++;
                j++;
         }
         for( i=0;i<r-l+1;i++)
         {
             strcpy(arr[l+i],ans[i]);
         }
    }
    void mergeSortStr(char arr[][50], int l, int r)
    {
        //code here
        if(l<r)
        {
            int m=l+(r-l)/2;
            mergeSortStr(arr,l,m);
            mergeSortStr(arr,m+1,r);
            mergeStr(arr,l,m,r);
        }
    }
    
    

void Max_MoM_Max_rungetter(int N, struct team t[N])
{
	int i, j, count1 = 0, x1 = 0;
	char namemom[100][100], s[100];

	int maxmom = 0;//calculating max no. of MoMs
	for (i = 0; i < N; i++)
	{

		for (j = 0; j < 15; j++)
		{
			if (t[i].p[j].MoM > maxmom)
			{
				maxmom = t[i].p[j].MoM;
			}
		}
	} 
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (maxmom == t[i].p[j].MoM)
			{

				strcpy(namemom[x1], t[i].p[j].player_id);//storing names of players with max MoMs in array of strings
				count1++;
				x1++;
			}
		}
	}

	for (i = 0; i < count1; i++)//sorting based on names
	{
		for (j = i + 1; j < count1; j++)
		{
			if (strcmp(namemom[i], namemom[j]) > 0)
			{
				strcpy(s, namemom[i]);
				strcpy(namemom[i], namemom[j]);
				strcpy(namemom[j], s);
			}
		}
	}
	printf("the players who won max MOM awards (%d) in the tournament are  ", maxmom);
	for (i = 0; i < count1; i++)
	{
		printf("%s", namemom[i]);
	}

	i = 0;
	j = 0;
	int count2 = 0;
	int x2 = 0;
	int flag=0;
	char nameruns[50][50], s2[100];

	int maxruns = 0;//calculating maximum runs
	for (i = 0; i < N; i++)
	{

		for (j = 0; j < 15; j++)
		{
			if (t[i].p[j].previous_total_score > maxruns)
			{
				maxruns = t[i].p[j].previous_total_score;
			}
		}
	} 
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (maxruns == t[i].p[j].previous_total_score)
			{

				strcpy(nameruns[x2], t[i].p[j].player_id);//storing names of players with max runs in array of strings
				count2++;
				x2++;
			}
		}
	}

//	for (i = 0; i < count2; i++)//sorting based on names
//	{
//		for (j = i + 1; j < count2; j++)
//		{
//			if (strcmp(nameruns[i], nameruns[j]) > 0)
//			{
//				strcpy(s2, nameruns[i]);
//				strcpy(nameruns[i], nameruns[j]);
//				strcpy(nameruns[j], s2);
//			}
//		}
//	}

	mergeSortStr(nameruns,0,count2-1);
	
	
	
	printf("the players who scored max runs(%d) in the tournament are ", maxruns);
	for (i = 0; i < count2; i++)
	{
		printf("%s", nameruns[i]);
	}
	if(count1==count2)
	{
		for(i=0;i<count1;i++)
		{
			if (strcmp(nameruns[i], namemom[i]) == 0)
			{
				flag=1;
			}
		}
    }
    if(flag==1)
    {
		printf("YES,the max runs scorers and the max MOM award winners are same\n");
	}
	else
	{
		printf("NO,the max runs scorers and the max MOM award winners are not the same\n ");
	}

	
}

void Highest_avg(int N, struct team t[N])
{
	int i, j, maxavg = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (t[i].p[j].previous_avg > maxavg)
			{
				maxavg = t[i].p[j].previous_avg > maxavg;
			}
		}
	}

	printf("The highest avg by an individual is %d", maxavg);
}

void difference(int N, struct team t[N])
{
	int i, j;
	int pwickets = 0, swickets = 0, diff;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (strcmp(t[i].p[j].player_role, "pacer") == 0)
			{
				pwickets = pwickets + t[i].p[j].previous_total_wickets;//wickets taken by pacers
			}
			if (strcmp(t[i].p[j].player_role, "spinner") == 0)
			{
				swickets = swickets + t[i].p[j].previous_total_wickets;//wickets taken by spinners
			}
		}
	}
	if (pwickets > swickets)
	{
		diff = pwickets - swickets;
	}
	else
	{
		diff = swickets - pwickets;
	}
	printf("Difference in the number of wickets taken by pacers and spinners of %s:%d",t[i].team_name, diff);
}

void K_times(int N, struct team t[N])
{
	int k, count = 0, i, j, maxcen = 0, x = 0;
	char ktimes[50][50], s[100], fin[50][50];
	int cen[100];
	printf("Enter the value of K :\n");
	scanf("%d", &k);
	for (i = 0; i < 100; i++)
	{
		cen[i] = 0;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (t[i].p[j].MoM >= k)//considering only those players having MoM more than or equal to k times
			{
				strcpy(ktimes[count], t[i].p[j].player_id);
				cen[count] = t[i].p[j].century;//storing no. of centuries in array
				count++;
			}
		}
	}

	for (i = 0; i < count; i++)
	{
		if (cen[i] > maxcen)
		{
			maxcen = cen[i];
		}
	}//maximum number of centuries
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (t[i].p[j].MoM >= k && t[i].p[j].century == maxcen)
			{
				strcpy(fin[x], t[i].p[j].player_id);//storing player names in array of strings
				x++;
			}
		}
	}

//	for (i = 0; i < x; i++)//sorting based on names
//	{
//		for (j = i + 1; j < x; j++)
//		{
//			if (strcmp(fin[i], fin[j]) > 0)
//			{
//				strcpy(s, fin[i]);
//				strcpy(fin[i], fin[j]);
//				strcpy(fin[j], s);
//			}
//		}
//	}
	
	mergeSortStr(fin,0,x-1);

	printf("the player(s) who were declared MOM for atleast %d times and have max centuries among such players is/are", k);
	for (i = 0; i < x; i++)
	{
		printf("%s", fin[i]);
	}
}

void possible_combinations(int N, struct team t[N])
{
	struct bestbatter tempbat[150];
	struct bestbowler tempbowl[150];
	int i, j, x = 0, y = 0, a1, a2;
	char playing11[11][100];



    //Best 2 batters
	for (i = 0; i < N; i++)
		{
			for (j = 0; j < 15; j++)
			{
				if (strcmp(t[i].p[j].player_role, "batsman") == 0)
				{
					strcpy(tempbat[x].player_id, t[i].p[j].player_id);
					tempbat[x].previous_total_score = t[i].p[j].previous_total_score;
					x++;
				}
			}
		}
		for (i = 0; i < x - 1; i++)
		{
			for (j = 0; j < x - i - 1; j++)
			{
				if (tempbat[j].previous_total_score > tempbat[j + 1].previous_total_score)
				{
					int a = tempbat[j].previous_total_score;
					tempbat[j].previous_total_score = tempbat[j].previous_total_score;
					tempbat[j + 1].previous_total_score = a;
				}
			}
		}
		strcpy(playing11[0], tempbat[x - 1].player_id);
		strcpy(playing11[1], tempbat[x - 2].player_id);
		
		
		//Best 2 bowlers
		y = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < 15; j++)
			{
				if (strcmp(t[i].p[j].player_role, "pacer") == 0 || strcmp(t[i].p[j].player_role, "spinner") == 0)
				{
					strcpy(tempbowl[y].player_id, t[i].p[j].player_id);
					tempbowl[y].previous_total_wickets = t[i].p[j].previous_total_wickets;
					y++;
				}
			}
		}

		for (i = 0; i < y - 1; i++)
		{
			for (j = 0; j < y - i - 1; j++)
			{
				if (tempbowl[j].previous_total_wickets > tempbowl[j + 1].previous_total_wickets)
				{
					int a = tempbowl[j].previous_total_wickets;
					tempbowl[j].previous_total_wickets = tempbowl[j].previous_total_wickets;
					tempbowl[j + 1].previous_total_wickets = a;
				}
			}
		}
		strcpy(playing11[2], tempbowl[y - 1].player_id);
		strcpy(playing11[3], tempbowl[y - 2].player_id);
		
		int bat;
		printf("Enter the number of batters you want in playing 11 (Minimum 5)");
		scanf("%d",&bat);
		
		int bowl;
		printf("Enter the number of batters you want in playing 11 (Minimum 4)");
		scanf("%d",&bowl);
		
		if(bat+bowl!=11)
		{
			printf("Total should be 11");
		}
		
		int player=4;
		bat=bat-2;
		bowl=bowl-2;
		while(bat)
		{
			strcpy(playing11[player],tempbat[x-2-bat].player_id);
			bat--;
			player++;
		}
		while(bowl)
		{
			strcpy(playing11[player],tempbat[x-2-bowl].player_id);
			bowl--;
			player++;
		}
		for(i=0;i<11;i++)
		{
			printf("%s\n",playing11[i]);
		}
		
}

main()
{
	int N;
	printf("Enter the number of teams(Even):");
	scanf("%d", &N);
	struct team t[N];
	int i, j;
	for (i = 0; i < N; i++)
	{
		printf("Enter team name: "); // names of the teams
		scanf("%s", t[i].team_name);
		for (j = 0; j < 15; j++)
		{
			printf("Enter the name of player %d: of %s ", j + 1, t[i].team_name); // names of the players of the team
			scanf("%s", t[i].p[j].player_id);
			printf("Enter player role: ");// Player roles Batter/Pacer/Spinner 
			scanf("%s", t[i].p[j].player_role);
		}
		if (i < N / 2)
		{
			t[i].grp = 'A'; // first N/2 teams in grp A
		}
		else
		{
			t[i].grp = 'B'; // next N/2 teams in grp B
		}
	}
	for (i = 0; i < N; i++)//Initialising all the stats to 0 before tournament
	{
		t[i].match_count = 0;
		for (j = 0; j < 15; j++)
		{
			t[i].p[j].previous_avg = 0;
			t[i].p[j].present_match_wicket = 0;
			t[i].p[j].previous_avg = 0;
			t[i].p[j].previous_total_score = 0;
			t[i].p[j].previous_total_wickets = 0; 
			t[i].p[j].previous_wicket_avg = 0;
			t[i].p[j].total_runs_in_last_five_matches = 0;
			t[i].p[j].total_wickets_in_last_five_matches = 0;
			t[i].p[j].century = 0;
			t[i].p[j].MoM = 0;
		}
	}
	int k = (N * (N - 2) / 4); // 2*(n/2)C2 total matches played
	struct match_played m[k];
	int temp1, temp2;
	for (i = 0; i < k; i++)
	{
		printf("Enter the match id:");
		scanf("%s", m[i].match_id);

		printf("Enter team 1:");
		scanf("%s", m[i].team1);

		printf("Enter team 2:");
		scanf("%s", m[i].team2);

		for (j = 0; j < N; j++)
		{
			if (strcmp(t[j].team_name, m[i].team1) == 0)//Identifying the serial number of team in which it was entered
			{
				temp1 = j;
			}
			if (strcmp(t[j].team_name, m[i].team2) == 0)
			{
				temp2 = j;
			}
		}
		t[temp1].match_count = t[temp1].match_count + 1;
		t[temp2].match_count = t[temp2].match_count + 1;//Incrementing match count 

		printf("Enter man of the match: ");
		scanf("%s", m[i].man_of_the_match);
		printf("MATCH RESULT: ");
		scanf("%s", m[i].match_result);

		int hs1 = 0;//for team 1
		for (j = 0; j < 15; j++)
		{
			printf("Enter the runs scored by the player %s  :", t[temp1].p[j].player_id);//Taking input of runs scored in each match
			scanf("%d", &t[temp1].p[j].present_match_score);

			if (t[temp1].p[j].present_match_score > hs1)//for calculating highest score
			{
				hs1 = t[temp1].p[j].present_match_score;
			}
			if (t[i].match_count > 1)
			{
				t[temp1].p[j].previous_avg = (t[temp1].p[j].previous_total_score / (t[i].match_count - 1));
				t[temp1].p[j].previous_total_score = t[temp1].p[j].previous_total_score + t[temp1].p[j].present_match_score;
			}
			if (t[temp1].p[j].present_match_score >= 100)
			{
				t[temp1].p[j].century = t[temp1].p[j].century + 1;
			}
			printf("Enter the wickets taken by the player :");//Input of wickets in every match
			scanf("%d", &t[temp1].p[j].present_match_wicket);
			if (t[i].match_count > 1)
			{

				t[temp1].p[j].previous_wicket_avg = (t[temp1].p[j].previous_total_wickets / (t[temp1].match_count - 1));
				t[temp1].p[j].previous_total_wickets = t[temp1].p[j].previous_total_wickets + t[temp1].p[j].present_match_wicket;
			}

			if (strcmp(m[i].man_of_the_match, t[temp1].p[j].player_id) == 0)
			{
				t[temp1].p[j].MoM = t[temp1].p[j].MoM + 1;
			}
		}
		int hs2 = 0;//For team 2
		for (j = 0; j < 15; j++)
		{
			printf("Enter the runs scored by the player %s :", t[temp2].p[j].player_id);
			scanf("%d", &t[temp2].p[j].present_match_score);

			if (t[temp2].p[j].present_match_score > hs2)
			{
				hs2 = t[temp2].p[j].present_match_score;
			}

			t[temp2].p[j].previous_total_score = t[temp2].p[j].previous_total_score + t[temp2].p[j].present_match_score;
			if (t[temp2].p[j].present_match_score >= 100)
			{
				t[temp2].p[j].century = t[temp2].p[j].century + 1;
			}
			printf("Enter the wickets taken by the player :");
			scanf("%d", &t[temp2].p[j].present_match_wicket);

			if (t[i].match_count > 1)
			{
				t[temp2].p[j].previous_wicket_avg = (t[temp2].p[j].previous_total_wickets / (t[i].match_count - 1));
				t[temp2].p[j].previous_total_wickets = t[temp2].p[j].previous_total_wickets + t[temp2].p[j].present_match_wicket;
			}
			if (strcmp(m[i].man_of_the_match, t[temp2].p[j].player_id) == 0)
			{
				t[temp2].p[j].MoM = t[temp2].p[j].MoM + 1;
			}
		}

		if (hs1 >= hs2)//Calculating highest run in a match
		{
			m[i].higest_run = hs1;
		}
		else
		{
			m[i].higest_run = hs2;
		}

		if (strcmp(m[i].match_result, t[temp1].team_name) == 0)//Giving 2 points to the winning team
		{
			t[temp1].points += 2;
		}

		if (strcmp(m[i].match_result, t[temp2].team_name) == 0)
		{
			t[temp2].points += 2;
		}

		else
		{
			t[temp1].points += 1;
			t[temp2].points += 1;//Giving both teams 1 poin in case of draw/tie
		}
	}

	int MaxPoints = 0;
	int MaxPoints2 = 0;//Calculating top two teams in points table of grp A
	for (i = 0; i < N / 2; i++)//grp A
	{
		if (t[i].points > MaxPoints)
		{
			MaxPoints2 = MaxPoints;
			MaxPoints = t[i].points;
		}
		if (t[i].points < MaxPoints && t[i].points > MaxPoints2)
		{
			MaxPoints2 = t[i].points;
		}
	}
	int sf1, sf2;
	for (i = 0; i < N; i++)
	{
		if (t[i].points == MaxPoints)
		{
			sf1 = i;
		}
		if (t[i].points == MaxPoints2)
		{
			sf2 = i;
		}
	}
	MaxPoints = 0;
	MaxPoints2 = 0;//Calculating top two teams in points table of grp B
	for (i = N / 2; i < N; i++) // grp B
	{
		if (t[i].points > MaxPoints)
		{
			MaxPoints2 = MaxPoints;
			MaxPoints = t[i].points;
		}
		if (t[i].points < MaxPoints && t[i].points > MaxPoints2)
		{
			MaxPoints2 = t[i].points;
		}
	}
	int sf3, sf4;
	for (i = N / 2; i < N; i++)
	{
		if (t[i].points == MaxPoints)
		{
			sf3 = i;
		}
		if (t[i].points == MaxPoints2)
		{
			sf4 = i;
		}
	}
	int f1, f2;
	for (i = k; i < k + 2; i++)//Input for semifinals
	{
		t[sf1].match_count = t[sf1].match_count + 1;
		t[sf2].match_count = t[sf2].match_count + 1;

		for (j = 0; j < 15; j++)
		{
			printf("Enter the runs scored by the player %s  :", t[sf1].p[j].player_id);
			scanf("%d", &t[sf1].p[j].present_match_score);
			t[sf1].p[j].previous_avg = (t[sf1].p[j].previous_total_score / (t[sf1].match_count - 1));
			t[sf1].p[j].previous_total_score = t[sf1].p[j].previous_total_score + t[sf1].p[j].present_match_score;
			printf("Enter the wickets taken by the player :");
			scanf("%d", &t[sf1].p[j].present_match_wicket);
			t[sf1].p[j].previous_wicket_avg = (t[sf1].p[j].previous_total_wickets / (t[sf1].match_count - 1));
			t[sf1].p[j].previous_total_wickets = t[sf1].p[j].previous_total_wickets + t[sf1].p[j].present_match_wicket;
			if (t[sf1].p[j].present_match_score >= 100)
				t[sf1].p[j].century += 1;
		}
		for (j = 0; j < 15; j++)
		{
			printf("Enter the runs scored by the player %s  :", t[sf2].p[j].player_id);
			scanf("%d", &t[sf2].p[j].present_match_score);
			t[sf2].p[j].previous_avg = (t[sf2].p[j].previous_total_score / (t[sf2].match_count - 1));
			t[sf2].p[j].previous_total_score = t[sf2].p[j].previous_total_score + t[sf2].p[j].present_match_score;
			printf("Enter the wickets taken by the player :");
			scanf("%d", &t[sf1].p[j].present_match_wicket);
			t[sf2].p[j].previous_wicket_avg = (t[sf2].p[j].previous_total_wickets / (t[sf2].match_count - 1));
			t[sf2].p[j].previous_total_wickets = t[sf2].p[j].previous_total_wickets + t[sf2].p[j].present_match_wicket;
			if (t[sf2].p[j].present_match_score >= 100)
				t[sf2].p[j].century += 1;
		}
		printf("Enter the man of the match:");
		scanf("%s", m[i].man_of_the_match);
		for (j = 0; j < 15; j++)
		{
			if (strcmp(m[i].man_of_the_match, t[sf1].p[j].player_id) == 0)
			{
				t[sf1].p[j].MoM = t[sf1].p[j].MoM + 1;
			}
			if (strcmp(m[i].man_of_the_match, t[sf1].p[j].player_id) == 0)
			{
				t[sf2].p[j].MoM = t[sf2].p[j].MoM + 1;
			}
		}
		printf("Enter match result:");
		scanf("%s", m[i].man_of_the_match);
		//deciding and identifying finalists
		if (strcmp(m[i].match_result, t[sf1].team_name) == 0 && i == k)
		{
			f1 = sf1;
		}
		if (strcmp(m[i].match_result, t[sf2].team_name) == 0 && i == k)
		{
			f1 = sf2;
		}
		if (strcmp(m[i].match_result, t[sf1].team_name) == 0 && i == k + 1)
		{
			f2 = sf1;
		}
		if (strcmp(m[i].match_result, t[sf2].team_name) == 0 && i == k + 1)
		{
			f2 = sf2;
		}

		sf1 = sf3;
		sf2 = sf4;
	}
	t[f1].match_count = t[f1].match_count + 1;
	t[f2].match_count = t[f2].match_count + 1;

	for (j = 0; j < 15; j++)//final
	{
		printf("Enter the runs scored by the player %s  :", t[f1].p[j].player_id);
		scanf("%d", &t[f1].p[j].present_match_score);
		t[f1].p[j].previous_avg = (t[f1].p[j].previous_total_score / (t[f1].match_count - 1));
		t[f1].p[j].previous_total_score = t[f1].p[j].previous_total_score + t[f1].p[j].present_match_score;
		printf("Enter the wickets taken by the player :");
		scanf("%d", &t[f1].p[j].present_match_wicket);
		t[f1].p[j].previous_wicket_avg = (t[f1].p[j].previous_total_wickets / (t[f1].match_count - 1));
		t[f1].p[j].previous_total_wickets = t[f1].p[j].previous_total_wickets + t[f1].p[j].present_match_wicket;
		if (t[f1].p[j].present_match_score >= 100)
			t[f1].p[j].century += 1;
	}
	for (j = 0; j < 15; j++)
	{
		printf("Enter the runs scored by the player %s  :", t[f2].p[j].player_id);
		scanf("%d", &t[f2].p[j].present_match_score);
		t[f2].p[j].previous_avg = (t[f2].p[j].previous_total_score / (t[f2].match_count - 1));
		t[f2].p[j].previous_total_score = t[f2].p[j].previous_total_score + t[f2].p[j].present_match_score;
		printf("Enter the wickets taken by the player :");
		scanf("%d", &t[sf1].p[j].present_match_wicket);
		t[f2].p[j].previous_wicket_avg = (t[f2].p[j].previous_total_wickets / (t[f2].match_count - 1));
		t[f2].p[j].previous_total_wickets = t[f2].p[j].previous_total_wickets + t[f2].p[j].present_match_wicket;
		if (t[f2].p[j].present_match_score >= 100)
			t[f2].p[j].century += 1;
	}
	printf("Enter the man of the match:");
	scanf("%s", m[i].man_of_the_match);
	for (j = 0; j < 15; j++)
	{
		if (strcmp(m[i].man_of_the_match, t[f1].p[j].player_id) == 0)
		{
			t[f1].p[j].MoM = t[f1].p[j].MoM + 1;
		}
		if (strcmp(m[i].man_of_the_match, t[sf1].p[j].player_id) == 0)
		{
			t[f2].p[j].MoM = t[f2].p[j].MoM + 1;
		}
	}
	char Winner[50];
	int w;
	printf("Enter match result:");
	scanf("%s", Winner);//Tournament winner
	for (j = 0; j < 15; j++)
	{
		if (strcmp(Winner, t[i].team_name) == 0)
		{
			w = i;
		}
	}
	possible_combinations(N, t);
	Max_MoM_Max_rungetter(N, t);
	Highest_avg(N, t);
	difference(N, t);
	K_times(N, t);
}
