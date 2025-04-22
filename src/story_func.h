#ifndef STORY_FUNC_H
#define STORY_FUNC_H

enum{
    CHOICE_ONE,
    CHOICE_TWO,
    CHOICE_MAX
};

void storyProcess();
void descriptionStory(const char *filename , const char *storytags);
void selectYesorNo();

#endif