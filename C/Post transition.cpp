#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
	
	printf("%s: \n", t.name);
	int office_loop, package_loop;
	
	for (office_loop = 0; office_loop < t.offices_count; office_loop ++) {
		printf("\t%d: \n",office_loop);
		for (package_loop = 0; package_loop < t.offices[office_loop].packages_count; package_loop++){
			printf("\t\t%s\n",t.offices[office_loop].packages[package_loop].id);
		}
	}

}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {	

int packages_send_number, packages_loop;
package* package_temp;
packages_send_number = (*source).offices[source_office_index].packages_count;
post_office* source_office;
post_office* target_office;
source_office = &((*source).offices[source_office_index]);
target_office = &((*target).offices[target_office_index]);

for (packages_loop = 0; packages_loop < packages_send_number; packages_loop++){
	package_temp = &source_office->packages[packages_loop];
	if(( package_temp -> weight <= target_office -> max_weight) 
	  && ( package_temp -> weight >= target_office -> min_weight)){
		target_office -> packages = (package *)realloc(target_office->packages, sizeof(package)*(target_office->packages_count+1));
	  	target_office -> packages_count ++;
	  	target_office -> packages[target_office -> packages_count-1] = *package_temp;
	  	source_office -> packages[packages_loop] = source_office -> packages[source_office->packages_count-1];
	  	source_office -> packages_count --;
	  	source_office -> packages = (package *)realloc(source_office->packages, sizeof(package)*(source_office->packages_count));

	  }
}
}


town town_with_most_packages(town* towns, int towns_count) {
	int town_loop, office_loop; 
	int packages_max = 0;
	int packages_temp = 0;
	town * thistown;
	town town_max;
	
	for (town_loop = 0; town_loop < towns_count; town_loop ++){
		thistown = towns + town_loop;
		packages_temp = 0;
		for (office_loop = 0; office_loop < thistown -> offices_count; office_loop ++){
			packages_temp = packages_temp + thistown -> offices[office_loop].packages_count;
		}
		if(packages_temp > packages_max){
			packages_max = packages_temp;
			town_max = *thistown;
		}
		
	}
	return town_max;
	
}

town* find_town(town* towns, int towns_count, char* name) {
	    int i;
    while(--towns_count>-1){
        if(strcmp(name, towns[towns_count].name)==0){
            i=towns_count;
        }
    }
    return towns+i;
	
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = (town *)malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = (post_office *)malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = (package *)malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t;
			t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source; 
			source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target;
			target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}


