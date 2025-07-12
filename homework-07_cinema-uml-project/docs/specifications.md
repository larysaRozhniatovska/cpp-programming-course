# ������ �������� �7: ������ ʳ������� - UML ������

#���� ��������
����� ������
������������ ������� ������-���������
������ ������� �������:
    ��������� �� ����������� ������������
    �������� �������� ������ � �����������
    ��������� �� ������ ������
    �������� ������ ������
    ��������� �������� �����������
    ������������� �������� (��� ������������)

���� ������������:
    ������ - ���� �����������, �������� �� ���������� ������
    ����������� - ���� ��������� ��������, ������������� �� ��������


      
homework-07_cinema-uml-project/
+-- README.md                 # ���� �������
+-- diagrams/
�   +-- use-case.png         # Use Case �������
�   +-- class-diagram.png    # Class �������  
�   +-- sequence-purchase.png # Sequence: �������
�   +-- sequence-[custom].png # ���� ����� sequence
�   L-- state-rental.png     # State �������
L-- docs/
    L-- specifications.md    # ������� ������������


## ĳ������
- Use Case: [use-case.png
		������: Guest(User), RegisteredUser, Admin
		Use Cases: Register, Login, LoginOut, View Movie Catalog,
			Purchase Movie, 
          		Rental Movie, Watch Movie, Manage profile, Manage Content.
		ó��� - ���� ��������������, ����� �� �������, ����������� ������
		������ - ���� �����������, �������� �� ���������� ������
    		����������� - ���� ��������� ��������, ������������� �� ��������]
- Class: [class-diagram.png  
		User 
		RegisteredUser 
		Admin 
		Movie
		Genre
		Purchase
		Rental
		PaymentMethod
		Review
		]  
- Sequence: [sequence-purchase.png + ������� "���������� ���� �����":
                ���������� ����� �����
    		������� �������� �������� ������
    		���������� ������� "������"
    		������� �������� �����������
    		³���������� ����� ������
    		���������� ������� ��� ������
    		������� �������� �����
    		������� ���� ������ �� ������
    		���������� ������ ������������

	      sequence-addMovie.png + ������� "����������� ���� ����� �����":
                �����������  ����� �����
    		������� �������� �������� ������
    		������� ���� �����
    		���������� ������ ������������
]

- State: [state-rental.png ���� ��� ��'���� "Rental" (������ ������):
	       Created > Active > Expired
    	       ��������� Cancelled �� ����-����� ����
    	       ��������� Extended � Active	]




    


      

        

