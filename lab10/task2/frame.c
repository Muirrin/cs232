/******************************************************
* File: frame.c
*
* This is the frame struct implementation
*
* Change Log:
* 12/02/2006, By Jun Yuan, created for CS101, Huazhong University of Sci. & Tech., Wuhan, China
* 01/05/2016, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 02/11/2017, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 02/18/2017, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 04/16/2019, By Jun Yuan-Murray, modified for CS232, Pace University, NY
* 04/29/2020, By Jun Yuan-Murray, modified for CS232, Pace University, NY
******************************************************/
#include "frame.h"
#include <stdlib.h>
#include <stdio.h>
static void load_frame(frame_t *f, char *path){
	// TODO:your code here
	// path is the pathname to an ascii file, we have to open the ascii file, and read the content
	// in line by line and store it in the frame->content
	// here is an example of reading line-by-line from path
	 FILE * fp;
   char * line = NULL;
	 size_t len = 50;
	 int fread;
	 int count = 0;
	 fp = fopen(path, "r");
    	 if (fp == NULL)
        	 exit(EXIT_FAILURE);



    	 while ((fread = getline(&line, &len, fp)) != -1) {
        	// printf("Retrieved line of length %zu:\n", read);
        	// printf("%s", line); //this line is NOT your code
		//your task is not to print the line, instead, you need to save the line to
		if(count == 0){
					f->rep_counter = atoi(line);

				}
		else if(count == 1){
			f->content  = (char*)malloc(fread+1);
			strcpy(f->content, line);
		}
		else{
				f->content  = (char*)realloc(f->content, fread+strlen(f->content)+1);
		 		strcat(f->content, line);
			}
		count++;
    	 }
	 fclose(fp);

	//also keep in mind, the first line is the repetition counter.
	//f->rep_counter = ...
	return;
}

frame_t * frame_new(char *pathname, int id) {
	//TODO: frame_new is not complete until load_frame is done
	frame_t * f = (frame_t *) malloc(sizeof(frame_t));
	if(!f) {
		perror("OOM, alloc failed\n");
		return 0;
	}
	f->id = id;
	load_frame(f, pathname);
	return f;
}

void frame_delete(frame_t * f) {
	//TODO: before we free f what inside f must be free-ed first?
	free(f->content); //not sure about this one, but it's the only pointer in f
	free(f);
}

char* frame_get_content (frame_t *f){
	return f-> content;
}
int frame_get_rep_counter(frame_t * f){
	return f-> rep_counter;
}
int frame_get_id(frame_t *f){
	return f-> id;
}
