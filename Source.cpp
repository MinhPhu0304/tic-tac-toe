#include <iostream>
#include <string>

using namespace std;

const int colum = 3;
char tic_tac_toe_board[3][3];

void print_empty_board_and_title(void);
void check_position_player_1(char tic_tac_toe_board[][colum], int row_input_from_user, int column_input_from_user);
void check_position_player_2(char tic_tac_toe_board[][colum], int row_input_from_user, int column_input_from_user);
void print_board( char tic_tac_toe_board[][colum]);
char check_patern_win(char tic_tac_toe_board[][colum]);
char check_patern_column(char coppy_from_board[][colum], int row);
char check_patern_row(char coppy_from_board[][colum],int row);
char check_patern_diagonal_left(char coppy_from_board[][colum], int row);
char check_patern_diagonal_right(char coppy_from_board[][colum],int row);
string check_who_win(char win_patern);

int main(void)
{
	char play_again = 'y';

	while (play_again == 'y')
	{
		int row_input_from_user;
		int column_input_from_user;

		//set all position in the board into empty space 
		for (int row = 0; row < 3; ++row)
		{
			for (int column = 0; column < 3; ++column)
			{
				tic_tac_toe_board[row][column] = '\0';
			}
		}

		print_empty_board_and_title();

		//each person will have 3 moves and the player 1 has extra 1 move. Stop the loop when player 1 chose the last position
		int number_of_move = 0;
		for (int turn = 0; turn < 8; ++turn)
		{
			cout << "\nplayer 1 you are X" << endl;
			cout << "Please enter your position you want(enter the first number as row then enter then enterthe second as column): ";
		
			cin >> row_input_from_user >> column_input_from_user;
		
			check_position_player_1(tic_tac_toe_board, row_input_from_user, column_input_from_user);
			
			print_board(tic_tac_toe_board);

			char win_value = check_patern_win(tic_tac_toe_board);

			if (number_of_move == 4 || win_value == 'X' || win_value == 'O' )
			{
				break;
			}

			cout << "\nplayer 2 you are O: ";
			cin >> row_input_from_user >> column_input_from_user;
		
			check_position_player_2(tic_tac_toe_board, row_input_from_user, column_input_from_user);

			print_board(tic_tac_toe_board);
			++number_of_move;

			win_value = check_patern_win(tic_tac_toe_board);

			if ( win_value == 'X' || win_value == 'O')
			{
				break;
			}
		}

		string result = check_who_win(check_patern_win(tic_tac_toe_board));
		cout << result << endl;

		cout << "Wanna play again(y/n) ? ";
		cin >> play_again;
	}

	cout << endl << "Goodbye player";

	return 0;
}

void check_position_player_1(char tic_tac_toe_board[][colum], int row_input_from_user, int column_input_from_user)
{
	if (row_input_from_user >= 3 || row_input_from_user < 0 || column_input_from_user >= 3 || column_input_from_user < 0)
	{
		cout <<"Are you trying to be funny or what? The row or col number is not even in range" << endl;
		cout << "Try again :";
		cin >> row_input_from_user >> column_input_from_user;
		check_position_player_1(tic_tac_toe_board, row_input_from_user, column_input_from_user);
		return;
	}
	if ( tic_tac_toe_board[row_input_from_user][column_input_from_user] == '\0')
	{
		tic_tac_toe_board[row_input_from_user][column_input_from_user] = 'X';
		return;
	}
	else
	{
			cout << "Sorry this position is already taken, please choose another position: ";
			cin >> row_input_from_user >> column_input_from_user;
			check_position_player_1(tic_tac_toe_board, row_input_from_user, column_input_from_user);
			return;
		}
	return;
}

void check_position_player_2(char tic_tac_toe_board[][colum], int row_input_from_user, int column_input_from_user)
{
	if (tic_tac_toe_board[row_input_from_user][column_input_from_user] == '\0')
	{
		tic_tac_toe_board[row_input_from_user][column_input_from_user] = 'O';
		return;
	}
	else
	{
			cout << "Sorry this position is already taken, please choose another position: ";
			cin >> row_input_from_user >> column_input_from_user;
			check_position_player_1(tic_tac_toe_board, row_input_from_user, column_input_from_user);
			return;
	}
	return;
}

void print_board(char tic_tac_toe_board[][colum])
{
	cout << "     0     1     2" << endl;

	for (int row = 0; row < 3; ++row)
	{
		cout << row << " ";
		for (int column = 0; column < 3; ++column)
		{
			if (tic_tac_toe_board[row][column] != NULL)
			{
			cout << " +_" << tic_tac_toe_board[row][column]<<"_+" ;
			}
			else
			{
				cout << " +___+";
			}
		}
		cout << endl;
	}
	return;
}

char check_patern_win(char tic_tac_toe_board[][colum])
{
	int row = 3;
	char result_array[4];
	
	char colum_check_result = check_patern_column(tic_tac_toe_board, row);
	result_array[0] = colum_check_result;

	char row_check_result = check_patern_row(tic_tac_toe_board, row);
	result_array[1] = row_check_result;
	
	char diagonal_left_result = check_patern_diagonal_left(tic_tac_toe_board, row);
	result_array[2] = diagonal_left_result;

	char diagonal_right_result = check_patern_diagonal_right(tic_tac_toe_board, row);
	result_array[3] = diagonal_right_result;

	char win_patern = NULL;

	for (int looked_element = 0; looked_element < 4; ++looked_element)
	{
		if (result_array[looked_element] == 'X' || result_array[looked_element] == 'O') 
		{
			win_patern = result_array[looked_element];
		}
	}
	
	if (win_patern == NULL)
	{
		win_patern = 'd';
		
		return win_patern;
	}
	else
	{
		return win_patern;
	}
}

char check_patern_column(char coppy_from_board[][colum], int row)
{
	int similarity_counter = 0;
	char repeat_3_time = NULL;
	char compare_char;

	for (int column_checked = 0; column_checked < 3; ++column_checked)
	{
		similarity_counter = 0;
		compare_char = tic_tac_toe_board[0][column_checked];

		for (int row_checked = 0; row_checked < row; ++row_checked)
		{
			//empty_position is boolean array
			if (tic_tac_toe_board[row_checked][column_checked] == compare_char && tic_tac_toe_board[row_checked][column_checked] != NULL )
			{
				similarity_counter++;
			}
			if (similarity_counter == 3)
			{
				repeat_3_time = tic_tac_toe_board[row_checked][column_checked];

				break;
			}
		}
		
	}
	
	if (repeat_3_time == NULL)
	{
		return 'd';
	}
	else
	{
		return repeat_3_time;
	}

}

char check_patern_row(char coppy_from_board[][colum], int row)
{
	int similarity_counter = 0;
	char repeat_3_time = NULL;
	char compare_char;

	for (int row_checked = 0; row_checked < 3; ++row_checked)
	{
		similarity_counter = 0;
		compare_char = tic_tac_toe_board[row_checked][0];

		for (int column_checked = 0; column_checked < row; ++column_checked)
		{
			if (tic_tac_toe_board[row_checked][column_checked] == compare_char && tic_tac_toe_board[row_checked][column_checked] != NULL)
			{
				similarity_counter++;
			}
			if (similarity_counter == 3)
			{
				repeat_3_time = tic_tac_toe_board[row_checked][column_checked];

				break;
			}
		}

	}

	if (repeat_3_time == NULL)
	{
		return 'd';
	}
	else
	{
		return repeat_3_time;
	}

}

char check_patern_diagonal_left(char coppy_from_board[][colum], int row)
{
	int similarity_counter = 0;
	char compare_char;
	
	compare_char = tic_tac_toe_board[0][0]; //starting point of the diagonal

	for (int row_checked = 0, column_checked = 0 ; row_checked < row; ++row_checked,++column_checked )
	{
		if (compare_char == tic_tac_toe_board[row_checked][column_checked] && tic_tac_toe_board[row_checked][column_checked] != NULL)
		{
			++similarity_counter;
		}
	}

	if (similarity_counter == 3)
	{
		return compare_char;
	}
	else
	{
		return 'd' ;
	}	
}

char check_patern_diagonal_right(char coppy_from_board[][colum], int row)
{
	int similarity_counter = 0;
	char compare_char = tic_tac_toe_board[0][2]; 

	for (int row_checked = 0, col_checked = row -1; row_checked < row; ++row_checked, --col_checked )
	{
		if (compare_char == tic_tac_toe_board[row_checked][col_checked] && tic_tac_toe_board[row_checked][col_checked] != NULL)
		{
			++similarity_counter;
		}
	}

	if (similarity_counter == 3)
	{
		return compare_char;
	}
	else
	{
		return 'd';
	}
}

string check_who_win(char win_patern) 
{
	if (win_patern == 'X')
	{
		return "Congratulation player 1 win";
	}
	else if (win_patern == 'O')
	{
		 return "Congratulation player 2 win";
	}
	else
	{
		return "This match is draw";
	}
}

void print_empty_board_and_title(void)
{
	cout << "This is a tic tac toe game" << endl;
	cout << "    0   1   2  " << endl;
	cout << "0 +___+___+___+ " << endl;
	cout << "1 +___+___+___+ " << endl;
	cout << "2 +___+___+___+ " << endl;
}