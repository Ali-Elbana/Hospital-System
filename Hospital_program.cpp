/* FILENAME: Hospital_program.cpp
*  Author:  Ali El-bana
*  Version:  V1.0
*  DATE:   Fri 07/21/2023
*/

#include <iostream>
#include <cstdio>
#include <string>

#include "Hospital_interface.hpp"
#include "Hospital_config.hpp"
#include "Hospital_private.hpp"

using namespace std ;

////////////////////////////////////////////////////////////////////
///////////////////// Functions Implementation ////////////////////
//////////////////////////////////////////////////////////////////

void Disp_vGUIWindow( void )
{
	
	cout<<endl								;
	cout<<endl <<"1) Add new patient" 		;
	cout<<endl <<"2) print all patients" 	;
	cout<<endl <<"3) Get next patient" 		;
	cout<<endl <<"4) Exit" 					;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Get_vWindowChoice( unsigned int & A_uintChoice )
{
	
	cout<<endl <<"Enter your choice: " ;
	cin>> A_uintChoice ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

bool Check_bValidWindowChoice( unsigned int A_uintChoice )
{
	
	bool isValid{true} ;
	
	if( (A_uintChoice != ADD)  && (A_uintChoice != PRINT) 
		&& 
		(A_uintChoice != NEXT) && (A_uintChoice != EXIT) )
	{
		
		isValid = false ;
		
	}
	else
	{
		isValid = true ;
	}
	
	return isValid ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Get_vSpecializationNum( unsigned int & A_uintSpecializationNum )
{
	
	cout<<endl <<"Enter specialization number(1-->20): " ;
	cin>> A_uintSpecializationNum ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

bool Check_bValidSpecializationNum( unsigned int A_uintSpecializationNum ) 
{
	
	bool isValid{true} ;
	
	if( (A_uintSpecializationNum - 1) < 0 || (A_uintSpecializationNum - 1) > (MAX_SPECIALIZATION-1) )
	{
		isValid = false ;
	}
	else
	{
		isValid = true ;
	}
	
	return isValid ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

bool Check_bSpecializationQueueFull( unsigned int A_uintspecializationQueue[],
									 unsigned int A_uintSpecializationNum	)
{
	bool isFull{false} ;
	
	if( A_uintspecializationQueue[A_uintSpecializationNum-1] >= MAX_PATIENTS )
	{
		isFull = true ;
	}
	else
	{
		isFull = false ;
	}

	return isFull ;
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Get_vPatientName( string & A_strName )
{
	
	// Empty the input buffer, to recieve another input //
	fflush( stdin ) ;
	
	cout<<endl <<"Enter patient name: " ;
	getline( cin, A_strName ) ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

bool Check_bEmptyString( string A_strString )
{
	
	bool isEmpty{false} ;
	
	if( A_strString.empty( ) != 0 ) 
	{
		isEmpty = true ;
	}
	else
	{
		isEmpty = false ;
	}
	
	for( char ch : A_strString ) 
	{
		
		// if you found any thing other than spaces break, cause it's not empty //  
		if( isspace(ch) == 0 ) 
		{
			isEmpty = false ;
			
			break ;
		}
		else
		{
			isEmpty = true ;
		}
	}

	return isEmpty ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

bool Check_bNumInString( string A_strString )
{
	
	bool foundNum{false} ;
	
	for( char ch : A_strString )
	{
		
		if( isdigit(ch) != 0 )
		{
			foundNum = true ;
			
			break ;
		}
		else
		{
			foundNum = false ;
		}
		
	}
	
	return foundNum ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

bool Check_bSpecialCharInString( string A_strString )
{
	
	bool foundSpecialChar{false} ;
	
	for( char ch : A_strString )
	{
		
		if( (isalnum(ch) == 0) && (ch != ' ') )
		{
			foundSpecialChar = true ;
			
			break ;
		}
		else
		{
			foundSpecialChar = false ;
		}
		
	}
	
	return foundSpecialChar ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

bool Check_bValidPatientName( string A_strName )
{
	
	bool isValid{true} 				;
	bool isEmpty{true} 				;
	bool containsNum{true} 			;
	bool containsSpecialChar{true} 	;
	
	isEmpty = Check_bEmptyString( A_strName ) ;
	
	if( isEmpty == true )
	{
		isValid = false ;
		
		cout<<endl <<"Invalid, you entered an empty name" ;
	}
	else
	{
		isValid = true ;
		
		containsNum = Check_bNumInString( A_strName ) ;
	
		if( containsNum == true )
		{
			isValid = false ;
		
			cout<<endl <<"Invalid, you entered number in the name" ;
		}
		else
		{
			isValid = true ;
			
			containsSpecialChar = Check_bSpecialCharInString( A_strName ) ;
	
			if( containsSpecialChar == true )
			{
				isValid = false ;
			
				cout<<endl <<"Invalid, you entered special character in the name" ;
			}
			else
			{
				isValid = true ;
			}
		}
		
	}
	
	return isValid ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Get_vPatientStatus( int & A_intPatientStatus )
{
	
	cout<<endl <<"Enter patient status(0-->regular, 1-->urgent): " ;
	cin>> A_intPatientStatus ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

bool Check_bValidPatientStatus( int A_intPatientStatus )
{
	
	bool isValid{true} ;
	
	if( (A_intPatientStatus != REGULAR) && (A_intPatientStatus != URGENT) )
	{
		isValid = false ;
	}
	else
	{
		isValid = true ;
	}
	
	return isValid ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Shift_vLeft( 	unsigned int A_uintSpecializationNum, string A_strPatientName, int A_intPatientStatus,
					string A_strPatientsNames[][MAX_PATIENTS], int A_intPatientsStatus[][MAX_PATIENTS]
				)
{
	
	for( int i = MAX_PATIENTS-2; i >= 0 ; i-- )
	{
		A_strPatientsNames[A_uintSpecializationNum-1][i+1] = A_strPatientsNames[A_uintSpecializationNum-1][i] ;
		
		A_intPatientsStatus[A_uintSpecializationNum-1][i+1] = A_intPatientsStatus[A_uintSpecializationNum-1][i] ;
	}
	
	A_strPatientsNames[A_uintSpecializationNum-1][0] = A_strPatientName ;
	
	A_intPatientsStatus[A_uintSpecializationNum-1][0] = A_intPatientStatus ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Add_vPatient( 	unsigned int A_uintSpecializationNum	  ,
					string A_strPatientName					  ,
					int A_intPatientStatus					  ,
					unsigned int A_uintspecializationQueue[]  ,
					string A_strPatientsNames[][MAX_PATIENTS] ,  
					int A_intPatientsStatus[][MAX_PATIENTS]
				 )
{
	
	// Add the patient info to your data: //
	// Add one more patient to the queue //
	A_uintspecializationQueue[A_uintSpecializationNum-1] = A_uintspecializationQueue[A_uintSpecializationNum-1] + 1 ;
	
	// Check for the patient status //
	if( A_intPatientStatus == REGULAR )
	{
		// Add his name //
		A_strPatientsNames[A_uintSpecializationNum-1][A_uintspecializationQueue[A_uintSpecializationNum-1]-1] = A_strPatientName ;
		
		// Add his status //
		A_intPatientsStatus[A_uintSpecializationNum-1][A_uintspecializationQueue[A_uintSpecializationNum-1]-1] = A_intPatientStatus ;							
	}
	// patient status is urgent //
	else
	{
		
		Shift_vLeft( A_uintSpecializationNum, A_strPatientName, A_intPatientStatus,
					 A_strPatientsNames, A_intPatientsStatus ) ;
		
	}
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Print_vAllPatients( unsigned int A_uintspecializationQueue[]  ,
						 string A_strPatientsNames[][MAX_PATIENTS] ,  
						 int A_intPatientStatus[][MAX_PATIENTS]
						) 

{
	
	for( int i = 0; i < MAX_SPECIALIZATION; i++ )
	{
		// Skip the empty specializations //
		if( A_uintspecializationQueue[i] == 0 )
		{
			continue ;
		}
		else
		{
			
			if( A_uintspecializationQueue[i] > 1 )
			{
				cout<<endl <<"There are " <<A_uintspecializationQueue[i] 
				<<" patients in specialization " <<i+1 <<':' ;
			}
			else
			{
				cout<<endl <<"There are " <<A_uintspecializationQueue[i] 
				<<" patient in specialization " <<i+1 <<':' ;
			}
			
			for( int j = 0; j < A_uintspecializationQueue[i]; j++ )
			{
				cout<<endl <<j+1 <<'-' <<A_strPatientsNames[i][j] <<' ' ;
				
				(A_intPatientStatus[i][j] == URGENT) ? cout<<"--> "<<"Urgent" : cout<<"--> "<<"Regular" ;
			}
			
		}
		
		cout<<endl ;
	}
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Shift_vRight( 	unsigned int A_uintSpecializationNum,
					string A_strPatientsNames[][MAX_PATIENTS], int A_intPatientsStatus[][MAX_PATIENTS] 
				)
{
	
	for( int i = 0; i < MAX_PATIENTS-1; i++ )
	{
		
		A_strPatientsNames[A_uintSpecializationNum-1][i] = A_strPatientsNames[A_uintSpecializationNum-1][i+1] ;
		
		A_intPatientsStatus[A_uintSpecializationNum-1][i] = A_intPatientsStatus[A_uintSpecializationNum-1][i+1] ;
		
	}
	
	A_strPatientsNames[A_uintSpecializationNum-1][MAX_PATIENTS-1] = "" ;
	
	A_intPatientsStatus[A_uintSpecializationNum-1][MAX_PATIENTS-1] = -1 ;
	
}
 
////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Get_vNextPatient( 	unsigned int A_uintspecializationQueue[], string A_strPatientsNames[][MAX_PATIENTS],
						int A_intPatientsStatus[][MAX_PATIENTS]
					)
{
	
	unsigned int specializationNum{0} ;
	
	Get_vSpecializationNum( specializationNum ) ;
	
	if( A_uintspecializationQueue[specializationNum-1] == EMPTY )
	{
		cout<<endl <<"No patients at the moment, have a rest doctor" ;
	}
	else
	{
		
		cout<<endl <<A_strPatientsNames[specializationNum-1][0] <<" please go to the doctor" ;
		
		Shift_vRight( specializationNum, A_strPatientsNames, A_intPatientsStatus ) ;
		
		// Remove one from the specialization queue //
		A_uintspecializationQueue[specializationNum-1] = A_uintspecializationQueue[specializationNum-1] - 1 ;
		
	}
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////




