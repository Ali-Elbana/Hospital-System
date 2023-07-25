/* FILENAME: main.cpp 
*  Author:  Ali El-bana
*  Version:  V1.0
*  DATE:   Fri 07/21/2023
*/

#include <iostream>
#include "Hospital_interface.hpp"

using namespace std ;

int main( void )
{
	
	system( "cls" ) ;
	
	unsigned int specializationQueue[MAX_SPECIALIZATION]{0} 	;
	string patientsNames[MAX_SPECIALIZATION][MAX_PATIENTS]{""} 	;
	int patientsStatus[MAX_SPECIALIZATION][MAX_PATIENTS]{-1} 	;
	
	unsigned int windowChoice{0} 			;
	bool isWindowOptionValid{false} 		;
	unsigned int specializationNum{0} 		;
	bool isSpecializationNumValid{false}	;
	bool isSpecializationQueueFull{true}	;
	string patientName{""}					;
	bool isPatientNameValid{false}			;
	int patientStauts{-1}					;
	bool isPatientStautsValid{false}		;
	
	cout<<endl <<"Welcome to the hospital system" ;
	
	do
	{
		
		/* 	
			Display GUI window 
			to choose one of these options:
			1) Add new patient" 	
			2) print all patients"
			3) Get next patient" 	
			4) Exit" 				
		*/
		Disp_vGUIWindow( ) ;
		
		// Get the choice from the user and hold it in 'windowChoice' //
		Get_vWindowChoice( windowChoice ) ;
		
		// Check if the user enters a choice from 1 to 4 //
		isWindowOptionValid = Check_bValidWindowChoice( windowChoice ) ;
		
		/* 	
			If window option isn't valid print warnning message,
			and ask him to enter the choice again, till he enters a valid choice
		*/
		if( isWindowOptionValid == false )
		{
			
			do
			{
				
				cout<<endl <<"Invalid option, try again by inserting an option from 1 to 4" ;
				
				// Get the choice from the user and hold it in 'windowChoice' //
				Get_vWindowChoice( windowChoice ) ;
		
				// Check if the user enters a choice from 1 to 4 //
				isWindowOptionValid = Check_bValidWindowChoice( windowChoice ) ;
		     
			}while( isWindowOptionValid == false ) ;
			
		}
		if( isWindowOptionValid == true )
		{
			
			switch( windowChoice )
			{
				
				case ADD: 
				 
					// Get specialization number, patient name and patient stauts //
					Get_vSpecializationNum( specializationNum ) ;
					Get_vPatientName( patientName ) ;
					Get_vPatientStatus( patientStauts ) ;
					
					// Check if the user enters a number from 1 to 20 //
					isSpecializationNumValid = Check_bValidSpecializationNum( specializationNum ) ;
					
					if( isSpecializationNumValid == false )
					{
					
						do
						{
							
							cout<<endl <<"Invalid specialization, try again by inserting a number from 1 to 20" ;
							
							Get_vSpecializationNum( specializationNum ) ;
					
							// Check if the user enters a number from 1 to 20 //
							isSpecializationNumValid = Check_bValidSpecializationNum( specializationNum ) ;
						 
						}while( isSpecializationNumValid == false ) ;
					 
					}
					if( isSpecializationNumValid == true )
					{
						
						isPatientNameValid = Check_bValidPatientName( patientName ) ;
						
						if( isPatientNameValid == false )
						{
							
							do
							{
								
								Get_vPatientName( patientName ) ;
						
								// Check if the user enters a valid name //
								isPatientNameValid = Check_bValidPatientName( patientName ) ;
							 
							}while( isPatientNameValid == false ) ;
						 
						}
						if( isPatientNameValid == true )
						{
							
							isPatientStautsValid = Check_bValidPatientStatus( patientStauts ) ;
							
							if( isPatientStautsValid == false )
							{
								do
								{
									
									cout<<endl <<"Invalid status, try again by inserting a number that is either 0 or 1" ;
									
									Get_vPatientStatus( patientStauts ) ;
								
									// Check if the user enters a number that is either 0 or 1 //
									isPatientStautsValid = Check_bValidPatientStatus( patientStauts ) ;
								 
								}while( isPatientStautsValid == false ) ;
								
							}
							if( isPatientStautsValid == true )
							{
								
								// Check that queue isn't full //
								isSpecializationQueueFull = Check_bSpecializationQueueFull( specializationQueue, specializationNum ) ;
								
								if( isSpecializationQueueFull == false )
								{
									
									Add_vPatient( 	specializationNum, patientName, patientStauts,
													specializationQueue, patientsNames, patientsStatus
												) ;
									
								}
								else
								{
									cout<<endl <<"Sorry, the queue is full we can't add more for this specialization" ;
								}
								
							}
							else
							{
								// Do nothing //
							}
							
						}
						else
						{
							// Do nothing //
						}
						
					}
					else
					{
						// Do nothing //
					}
			     
				break ;
				/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
				case PRINT: 
				 
					Print_vAllPatients( specializationQueue, patientsNames, patientsStatus ) ;
				 
				break ;
				/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
				case NEXT: 
				 
					Get_vNextPatient( specializationQueue, patientsNames, patientsStatus ) ;
				 
				break ;
				/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
				case EXIT: 
				 
					cout<<endl <<"Exit from the hospital system" <<endl ;
				 
				break ;
				/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
				default:
				
					// Do nothing //
					
				break ;
				
			}//{switch bracket}//
			
		}//{isWindowOptionValid true bracket}//
		else
		{
			// Do nothing //
		}
		
	}while( windowChoice != EXIT ) ;
	
}//{main bracket}//



