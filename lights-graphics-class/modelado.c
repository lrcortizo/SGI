/*************************************************************************/
/*                                                                       */
/*   modelado.c                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

#include <stdio.h>
#include "glig.h"
#include "modelado.h"


/******************************************************************************************/
/* Crea las distintas display lists                                                       */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaDisplayLists (void)
{

	CreaEscena ();
}


/******************************************************************************************/
/* Dibuja la escena                                                                       */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void DibujaEscena (void)
{
	glCallList (escena);
}


/******************************************************************************************/
/*  Crea una display list para toda la escena                                             */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CreaEscena(void)
{
	escena = glGenLists (1);

	if (escena != 0)
	{
		glNewList (escena, GL_COMPILE);

		// TODO 06:  COMMENT SPHERE DRAWING AND DRAW A CUBE USING "igSolidCubo" FROM glig
		
		// TODO 09: CALL THE FUNCTION THAT DRAWS THE NEW CUBE AND SCALE IT (5.f, 5.f, 5.f)
		//glScalef(5.f, 5.f, 5.f);
		//igSolidCubo();
		//igSolidCubo_2();
		// TODO 10: COMMENT THE CUBE AND UNCOMMENT THE SOLID SPHERE DRAWING

		// TODO 14: DEFINE MATERIAL PROPERTIES FOR THE SOLID SPHERE

		/*
		NOTE: When a object is illuminated, its reaction depends on its material. Each material could have these properties:

		+ AMBIENT color. Most common: NNatural color of the object
		+ DIFFUSE color. Most common: Natural color of the object 
		+ SPECULAR color. Color of highlight.  Most common: white
		+ SHININESS: Specular exponent. Low -> spread hightlight. High -> concentrated highlight
		+ EMISSION: Simulare material light emission

		*/

		// 14.1. RED AMBIENT COLOR
		GLfloat red_ambient[] = { 1.f, 0.f, 0.f, 1.f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, red_ambient);
		// 14.2. RED DIFFUSE COLOR
		GLfloat red_diffuse[] = { 1.f, 0.5f, 0.5f, 1.f };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, red_diffuse);
		// 14.3. WHITE SPECULAR COLOR
		GLfloat white_specular[] = { 1.f, 1.f, 1.f, 1.f };
		glMaterialfv(GL_FRONT, GL_SPECULAR, white_specular);
		// 14.4 SHININESS OF 20
		GLfloat high_shininess = 20.f;
		glMaterialf(GL_FRONT, GL_SHININESS, high_shininess);
		// 14.5 LOW EMISSION 
		GLfloat mat_emission[] = { 0.1f, 0.1f, 0.1f, 1.f };
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

		glutSolidSphere(5.f, 20, 16);

		glEndList ();
	}
	else puts ("Se ha producido un error creando la display list de la escena.");
}
