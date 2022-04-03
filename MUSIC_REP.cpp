
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>
	class Music
	{
		char artist[20];
		int album_no;
		int cop;
		char album[20];
		float price;
		char customer[15];
		char type[10];
	public: void display();
		void get();
		int alb()
		{
			return album_no;
		}
		int price1()
		{
			return price;
		}
		void setprice()
		{
			cout<<"Enter the NEW price: "<<endl;
			cin>>price;
		}
	}c;
	void Music::get()
	{
		clrscr();
		cout<<"Enter your Name:"<<endl;
		gets(customer);
		cout<<"Enter the Album number:"<<endl;
		cin>>album_no;
		cout<<"Enter the Artist name:"<<endl;
		gets(artist);
		cout<<"Enter the Album name:"<<endl;
		gets(album);
		cout<<"Enter the Number of Albums in stock:"<<endl;
		cin>>cop;
		cout<<"Enter the Amount:"<<endl;
		cin>>price;
		cout<<"Enter the type of Format present (CD/MP3/MP4):"<<endl;
		gets(type);
	}
	void insert()
	{
		clrscr();
		fstream file;
		file.open("Music_rec.txt",ios::binary|ios::out);
		c.get();
		while(file.read((char*)&c,sizeof(c)))
			file.write((char*)&c,sizeof(c));
		file.close();
	}
	void Music::display()
	{
		cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Album number:"<<album_no<<"\nArtist name: "<<artist<<"\nAlbum name:"<<album<<endl;
		cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Number of Albums in stock: "<<cop<<"\nAmount including tax: "<<price<<"\nFormat: "<<type<<endl;
	}
	void output1()
	{
		clrscr();
		fstream file;
		file.open("Music_rec.txt",ios::binary|ios::in);
		while(file.read((char*)&c,sizeof(c)))
			c.display();
		file.close();
	}
	void search()
	{
		clrscr();
		int x;
		fstream file;
		file.open("Music_rec.txt",ios::binary|ios::in);
		int album__no;
		float price_s;
		cout<<"Enter 1 to search based on Album number or 2 to search based on price"<<endl;
		cout<<"--------------------------------------------------------------------------------\n";
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cin>>x;
		switch(x)
		{
			case 1: cout<<"Enter the Album number to be searched"<<endl;
				cin>>album__no;
				int flag=0;
				while(file.read((char*)&c,sizeof(c)))
				{
					if(album__no==c.alb())
					{
						c.display();
						flag=1;
					}
				}
				if(flag==0)
					cout<<"Record not found"<<endl;
				else
					cout<<"Record found"<<endl;
				break;
			case 2: cout<<"Enter the price to be searched"<<endl;
				cin>>price_s;
				int f=0;
				while(file.read((char*)&c,sizeof(c)))
				{
					if(price_s==c.price1())
					{
						c.display();
						f=1;
					}
				}
				if(f==0)
					cout<<"Record found."<<endl;
				else
					cout<<"Record not found"<<endl;
				break;
			default: cout<<"Invalid input"<<endl;
		}
		file.close();

	}
	void modify()
	{
		fstream file;
		int alb_n;
		file.open("Music_rec.dat",ios::binary|ios::in|ios::out);
		cout<<"Enter the Album number"<<endl;
		cin>>alb_n;
		int record=0;
		while(file.read((char*)&c,sizeof(c)))
		{
			if(alb_n==c.alb())
			{

				c.setprice();
				file.seekp(record*sizeof(c),ios::beg);
				file.write((char*)&c,sizeof(c));
			}
			record++;
		}
		file.close();
	}
	void delete_record()
	{
		clrscr();
		fstream fin,fout;
		fin.open("Music_rec.txt",ios::binary|ios::in);
		fout.open("Temp_music_rec.txt",ios::binary|ios::out);
		int alb_no;
		cout<<"Enter the album number whose record is to be deleted"<<endl;
		cin>>alb_no;
		int flag;
		while(fin.read((char*)&c,sizeof(c)))
		{
			if(alb_no==c.alb())
				flag=1;
			else
				fout.write((char*)&c,sizeof(c));
		}
		if(flag==1)
			cout<<"Record is deleted"<<endl;
		fout.close();
		fin.close();
		remove("Music_rec.txt");
		rename("Temp_music_rec.txt","Music_rec.txt");
	}
	void main()
	{
		clrscr();
		int choice;
		do
		{
			clrscr();
			cout<<"Welcome to ****Reverend Music store***"<<endl;
			cout<<"Please choose from below menu: "<<endl;
			cout<<"------------------------------------------"<<endl;
			cout<<"------------------------------------------"<<endl;
			cout<<" 1.Admin \n 2.User \n 3.Exit"<<endl;
			cin>>choice;
			switch(choice)
			{
				case 1: int c1;
					clrscr();
					cout<<"Please choose from the given menu: "<<endl;
					cout<<" 1.Insert new album record \n 2.Display records \n 3.Search a record \n 4.Modify a record \n 5.Delete a record \n 6.Exit"<<endl;
					cin>>c1;
					switch(c1)
					{
						case 1: insert();
							break;
						case 2: output1();
							break;
						case 3: search();
							break;
						case 4: modify();
							break;
						case 5: delete_record();
							break;
						case 6: exit(0);
						default: cout<<"Invalid Input"<<endl;
					}
					break;
				case 2: clrscr();
					int c2;
					cout<<"Please choose from the given menu: "<<endl;
					cout<<" 1.Search \n 2.Display \n 3.Exit"<<endl;
					cin>>c2;
					switch(c2)
					{
						case 1: search();
							break;
						case 2: output1();
							break;
						case 3: exit(0);
						default: cout<<"Invalid Input"<<endl;
					}
					break;
				case 3: exit(0);
				default: cout<<"Invalid input!"<<endl;
			}
		}
		while(choice!=0);
		getch();
	}














