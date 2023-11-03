#include "command.h"


char **split_string(char *input, char *delimiters)
{
    int i = 0, wordIndex = 0, wordLength, charIndex;
    int numWords = 0;
    char **wordArray;

    if (input == NULL || input[0] == 0)
        return NULL;

    if (!delimiters)
        delimiters = " ";

    while (input[i] != '\0')
    {
        if (!is_delimiter(input[i], delimiters) && (is_delimiter(input[i + 1], delimiters) || !input[i + 1]))
            numWords++;

        i++;
    }

    if (numWords == 0)
        return NULL;

    wordArray = malloc((1 + numWords) * sizeof(char *));
    if (!wordArray)
        return NULL;

    i = 0;
    while (wordIndex < numWords)
    {
        while (is_delimiter(input[i], delimiters))
            i++;

        wordLength = 0;
        while (!is_delimiter(input[i + wordLength], delimiters) && input[i + wordLength])
            wordLength++;

        wordArray[wordIndex] = malloc((wordLength + 1) * sizeof(char));

        if (!wordArray[wordIndex])
        {
            wordLength = 0;
            while (wordLength < wordIndex)
            {
                free(wordArray[wordLength]);
                wordLength++;
            }
            free(wordArray);
            return NULL;
        }

        charIndex = 0;
        while (charIndex < wordLength)
        {
            wordArray[wordIndex][charIndex] = input[i++];
            charIndex++;
        }

        wordArray[wordIndex][charIndex] = 0;
        wordIndex++;
    }

    wordArray[wordIndex] = NULL;
    return wordArray;
}

