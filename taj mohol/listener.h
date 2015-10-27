void keyboardListener(unsigned char key, int x,int y){
	switch(key){
		case '1':	
			lookLeft();
			break;

		case '2':	
			lookRight();
			break;

		case '3':	
			lookUp();
			break;
		case '4':	
			lookDown();
			break;
		case '5':	
			lookScrewLeft();
			break;
		case '6':	
			lookScrewRight();
			break;
		case '8':	
			canDrawGrid = 1 - canDrawGrid;
			break;
		case 'w':	
			moveForword();
			break;
		case 's':	
			moveBackword();
			break;
		case 'a':	
			moveLeft();
			break;
		case 'd':	
			moveRight();
			break;
		case 'q':	
			moveUp();
			break;
		case 'e':	
			moveDown();
			break;
		case 'r':	
			resetCamera();
			break;
		case 'k':	
			saveCameraData();
			break;
		case 'l':	
			loadCameraData();
			break;
		case 27:	//ESCAPE KEY -- simply exit
			exit(0);
			break;

		default:
			break;
	}
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			//cameraRadius += 10;
			break;
		case GLUT_KEY_UP:		// up arrow key
			break;

		case GLUT_KEY_RIGHT:
			break;
		case GLUT_KEY_LEFT:
			break;

		case GLUT_KEY_PAGE_UP:
			//cameraZ += 10;
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}

void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}