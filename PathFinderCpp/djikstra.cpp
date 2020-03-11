#include "bots.h"

void cDijkstra::Build(cBotBase& bot)
{
	for (int i = 0; i < GRIDWIDTH; i++)
	{
		for (int j = 0; j < GRIDHEIGHT; j++)
		{
			//Initialising the data arrays.
			closed[i][j] = false;
			cost[i][j] = 1000000.0f;
			linkX[i][j] = -1;
			linkY[i][j] = -1;
			inPath[i][j] = false;
		}
	}

	cost[bot.PositionX()][bot.PositionY()] = 0;

	int lowestCostX, lowestCostY;
	float lowestCostTile;


	while (!closed[gTarget.PositionX()][gTarget.PositionY()])
	{	
		lowestCostTile = 1000000.0f;

		/*Finds the current lowest cost tile in the grid*/
		for (int i = 0; i < GRIDWIDTH; i++)
		{
			for (int j = 0; j < GRIDHEIGHT; j++)
			{
				if (!closed[i][j] && gLevel.isValid(i, j))
				{
					if (cost[i][j] < lowestCostTile)
					{
						lowestCostX = i;
						lowestCostY = j;
						lowestCostTile = cost[i][j];
					}
				}
			}
		}

		/*Right Neighbour*/
		if (gLevel.isValid(lowestCostX + 1, lowestCostY) && !closed[lowestCostX + 1][lowestCostY])
		{
			if (cost[lowestCostX + 1][lowestCostY] > cost[lowestCostX][lowestCostY] + 1)
			{
				cost[lowestCostX + 1][lowestCostY] = cost[lowestCostX][lowestCostY] + 1;
				linkX[lowestCostX + 1][lowestCostY] = lowestCostX;
				linkY[lowestCostX + 1][lowestCostY] = lowestCostY;
			}

		}

		/*Left Neighbour*/
		if (gLevel.isValid(lowestCostX - 1, lowestCostY) && !closed[lowestCostX - 1][lowestCostY])
		{
			if (cost[lowestCostX - 1][lowestCostY] > cost[lowestCostX][lowestCostY] + 1)
			{
				cost[lowestCostX - 1][lowestCostY] = cost[lowestCostX][lowestCostY] + 1;
				linkX[lowestCostX - 1][lowestCostY] = lowestCostX;
				linkY[lowestCostX - 1][lowestCostY] = lowestCostY;
			}
		}

		/*Upper Neighbour*/
		if (gLevel.isValid(lowestCostX, lowestCostY - 1) && !closed[lowestCostX][lowestCostY - 1])
		{
			if (cost[lowestCostX][lowestCostY - 1] > cost[lowestCostX][lowestCostY] + 1)
			{
				cost[lowestCostX][lowestCostY - 1] = cost[lowestCostX][lowestCostY] + 1;
				linkX[lowestCostX][lowestCostY - 1] = lowestCostX;
				linkY[lowestCostX][lowestCostY - 1] = lowestCostY;
			}
		}

		/*Lower Neighbour*/
		if (gLevel.isValid(lowestCostX, lowestCostY + 1) && !closed[lowestCostX][lowestCostY + 1])
		{
			if (cost[lowestCostX][lowestCostY + 1] > cost[lowestCostX][lowestCostY] + 1)
			{
				cost[lowestCostX][lowestCostY + 1] = cost[lowestCostX][lowestCostY] + 1;
				linkX[lowestCostX][lowestCostY + 1] = lowestCostX;
				linkY[lowestCostX][lowestCostY + 1] = lowestCostY;
			}
		}

		/*Upper Right Neighbour*/
		if (gLevel.isValid(lowestCostX + 1, lowestCostY - 1) && !closed[lowestCostX + 1][lowestCostY - 1])
		{
			if (cost[lowestCostX + 1][lowestCostY - 1] > cost[lowestCostX][lowestCostY] + 1.4f)
			{
				cost[lowestCostX + 1][lowestCostY - 1] = cost[lowestCostX][lowestCostY] + 1.4f;
				linkX[lowestCostX + 1][lowestCostY - 1] = lowestCostX;
				linkY[lowestCostX + 1][lowestCostY - 1] = lowestCostY;
			}
		}

		/*Upper Left Neighbour*/
		if (gLevel.isValid(lowestCostX - 1, lowestCostY - 1) && !closed[lowestCostX - 1][lowestCostY - 1])
		{
			if (cost[lowestCostX - 1][lowestCostY - 1] > cost[lowestCostX][lowestCostY] + 1.4f)
			{
				cost[lowestCostX - 1][lowestCostY - 1] = cost[lowestCostX][lowestCostY] + 1.4f;
				linkX[lowestCostX - 1][lowestCostY - 1] = lowestCostX;
				linkY[lowestCostX - 1][lowestCostY - 1] = lowestCostY;
			}
		}

		/*Lower Right Neighbour*/
		if (gLevel.isValid(lowestCostX + 1, lowestCostY + 1) && !closed[lowestCostX + 1][lowestCostY + 1])
		{
			if (cost[lowestCostX + 1][lowestCostY + 1] > cost[lowestCostX][lowestCostY] + 1.4f)
			{
				cost[lowestCostX + 1][lowestCostY + 1] = cost[lowestCostX][lowestCostY] + 1.4f;
				linkX[lowestCostX + 1][lowestCostY + 1] = lowestCostX;
				linkY[lowestCostX + 1][lowestCostY + 1] = lowestCostY;
			}
		}

		/*Lower Left Neighbour*/
		if (gLevel.isValid(lowestCostX - 1, lowestCostY + 1) && !closed[lowestCostX - 1][lowestCostY + 1])
		{
			if (cost[lowestCostX - 1][lowestCostY + 1] > cost[lowestCostX][lowestCostY] + 1.4f)
			{
				cost[lowestCostX - 1][lowestCostY + 1] = cost[lowestCostX][lowestCostY] + 1.4f;
				linkX[lowestCostX - 1][lowestCostY + 1] = lowestCostX;
				linkY[lowestCostX - 1][lowestCostY + 1] = lowestCostY;
			}
		}

		//Set the current lowest cost grid as closed or 'visited'
		closed[lowestCostX][lowestCostY] = true;
	}

	bool done = false; //set to true when we are back at the bot position
	int nextClosedX = gTarget.PositionX(); //start of path
	int nextClosedY = gTarget.PositionY(); //start of path
	while (!done)
	{
		inPath[nextClosedX][nextClosedY] = true;
		int tmpX = nextClosedX;
		int tmpY = nextClosedY;
		nextClosedX = linkX[tmpX][tmpY];
		nextClosedY = linkY[tmpX][tmpY];
		if ((nextClosedX == bot.PositionX()) && (nextClosedY == bot.PositionY()))
			done = true;
	}

	//Dijkstra's Algorithm is complete
	completed = true;
}

cDijkstra gDijkstra;