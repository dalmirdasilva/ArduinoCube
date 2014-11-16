
	int x, i, xyz;
	for (x=0;x<iterations;x++)
	{
		for (i=0;i<16;i++)
		{
            xyz = 7-i; // This reverses counter i between 0 and 7.
            if (i > 7)
                xyz = i-8; // at i > 7, i 8-15 becomes xyz 0-7.

            fill(0x00); delay_ms(1);
            cli(); // disable interrupts while the cube is being rotated
			box_wireframe(0,0,0,xyz,xyz,xyz);

            if (flip > 0) // upside-down
                mirror_z();

            if (rot == 1 || rot == 3)
                mirror_y();

            if (rot == 2 || rot == 3)
                mirror_x();

            sei(); // enable interrupts
			delay_ms(delay);
	        fill(0x00);
        }
    }