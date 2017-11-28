#include<stdio.h>
#include<stdlib.h>
#define ISSUE 5
#define RATINGS 10

void recordResponse(int i, int responce);
void highestRatings();
void lowestRatings();
float averageRating(int issue);
void dispalyResults();

int responses[ISSUE][RATINGS];
const char *topics[ISSUE] = { "Global Warming","The Economy","War","Health Care","Education" };

int main(void)
{
	int response, i;
	do
	{
		printf("Please rate the following topics on a scale from 1 - 10"
			"\n 1 = least important, 10 = most important\n");
		for (i = 0; i < ISSUE; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("? ");
				scanf("%d", &response);
			} while (response < 1 || response >10);
			recordResponse(i, response);
		}
		printf("Enter 1 to stop. Enter 0 to rate the issues again. ");
		scanf("%d", &response);
	} while (response != 1);
	dispalyResults();
	system("pause");
	return 0;
}

void recordResponse(int issue, int rating)
{
	responses[issue][rating - 1]++;
}
void highestRatings()
{
	int highRating = 0;
	int highTopic = 0;
	int i, j;
	for (i = 0; i < ISSUE; i++)
	{
		int topicRating = 0;
		for (j = 0; j < RATINGS; j++)
		{
			topicRating += responses[i][j] * (j + 1);
		}
		if (highRating < topicRating)
		{
			highRating = topicRating;
			highTopic = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s", topics[highTopic]);
	printf(" with a total rating of %d\n", highRating);
}
void lowestRatings(void)
{
	int lowRating, i, j;
	int lowTopic = 0;
	for (i = 0; i < ISSUE; i++)
	{
		int topicRating = 0;
		for (j = 0; j < RATINGS; j++)
		{
			topicRating += responses[i][j] * (j + 1);
		}
		if (i==0)
		{
			lowRating = topicRating;
		}
		if (lowRating > topicRating)
		{
			lowRating = topicRating;
			lowTopic = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lowTopic]);
	printf(" with a total rating of %d\n", lowRating);
}
float averageRating(int issue)
{
	float total = 0;
	int j, counter = 0;
	for (j = 0; j < RATINGS; j++)
	{
		if (responses[issue][j] != 0)
		{
			total += responses[issue][j] * (j + 1);
			counter += responses[issue][j];
		}
	}
	return total / counter;
}
void dispalyResults()
{
	int i; int j;
	printf("%20s", "Topic");
	for (i = 1; i <= RATINGS; i++)
	{
		printf("%4d", i);
	}
	printf("%20s", "Average Rating");
	for (i = 0; i < ISSUE; i++)
	{
		printf("%20s", topics[i]);
		for (j = 0; j < RATINGS; j++)
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f", averageRating(i));
	}
	highestRatings();
	lowestRatings();
}