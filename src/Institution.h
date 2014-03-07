#ifndef _INSTITUTION_H__
#define _INSTITUTION_H__

typedef enum {Unknown, University, UniversityCollege, College} InstitutionType;

typedef struct Institution_t {
	char *name;
	char *address;
	unsigned long postcode;
	unsigned long int telephone;
	InstitutionType type;
	int yearEstablished;
} Institution;

#endif //_INSTITUTION_H__