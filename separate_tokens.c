#include "shell.h"

/**
  * tokenLength - finds the delimiter index
  * @stream: the string contsining delimiters
  * @delim: delimiter character
  * Return: length of string before delimiter
  */
int tokenLength(char *stream, char *delim)
{
	int itr = 0, length = 0;

	while (*(stream + itr) && *(stream + itr) != *delim)
	{
		length++;
		itr++;
	}
	return (length);
}
/**
  * tokenCount - counts number of words separated by delimiters
  * @stream: string to find tokens
  * @delim: the delimiter character
  * Return: number of words in stream
  */
int tokenCount(char *stream, char *delim)
{
	int itr, words = 0, length = 0;

	for (itr = 0; *(stream + itr); itr++)
		length++;
	for (itr = 0; itr < length; itr++)
	{
		if (*(stream + itr) != *delim)
		{
			words++;
			itr += tokenLength(stream + itr, delim);
		}
	}
	return (words);
}
/**
  * strtok_fn - Tokenizes stream
  * @stream: string to tokenize
  * @delim: delimiters
  * Return: pointer to array of words
  */
char **strtok_fn(char *stream, char *delim)
{
	char **words;
	int itr = 0;
	int the_words, a, characters, b;

	the_words = tokenCount(stream, delim);
	if (the_words == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (the_words + 2));
	if (!words)
		return (NULL);
	for (a = 0; a < the_words; a++)
	{
		while (stream[itr] == *delim)
			itr++;
		characters = tokenLength(stream + itr, delim);
		words[a] = malloc(sizeof(char) * (characters + 1));
		if (!words[a])
		{
			for (itr -= 1; itr >= 0; itr--)
				free(words[itr]);
			free(words);
			return (NULL);
		}
		for (b = 0; b < characters; b++)
		{
			words[a][b] = stream[itr];
			itr++;
		}
		words[a][b] = '\0';
	}
	words[a] = NULL;
	words[a + 1] = NULL;
	return (words);
}


