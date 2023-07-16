VERSION 4.00
Begin VB.Form MainForm 
   Caption         =   "Tic Tac Toe"
   ClientHeight    =   3375
   ClientLeft      =   1155
   ClientTop       =   1785
   ClientWidth     =   6615
   BeginProperty Font 
      name            =   "MS Sans Serif"
      charset         =   0
      weight          =   400
      size            =   9.75
      underline       =   0   'False
      italic          =   0   'False
      strikethrough   =   0   'False
   EndProperty
   Height          =   4065
   Icon            =   "TICTAC.frx":0000
   Left            =   1095
   LinkTopic       =   "MainForm"
   MaxButton       =   0   'False
   ScaleHeight     =   3375
   ScaleWidth      =   6615
   Top             =   1155
   Width           =   6735
   Begin Threed.SSPanel MainForm 
      Height          =   3135
      Left            =   240
      TabIndex        =   14
      Top             =   120
      Width           =   6135
      _Version        =   65536
      _ExtentX        =   10821
      _ExtentY        =   5530
      _StockProps     =   15
      BackColor       =   12632256
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         name            =   "MS Sans Serif"
         charset         =   0
         weight          =   400
         size            =   8.25
         underline       =   0   'False
         italic          =   0   'False
         strikethrough   =   0   'False
      EndProperty
      Begin Threed.SSPanel CurrentPlayerPanel 
         Height          =   615
         Left            =   4200
         TabIndex        =   12
         Top             =   480
         Width           =   1215
         _Version        =   65536
         _ExtentX        =   2143
         _ExtentY        =   1085
         _StockProps     =   15
         BackColor       =   12632256
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "MS Sans Serif"
            charset         =   0
            weight          =   700
            size            =   9.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         BevelOuter      =   0
         BevelInner      =   1
         Font3D          =   2
      End
      Begin Threed.SSCommand btnStartNewGame 
         Height          =   495
         Left            =   3720
         TabIndex        =   9
         Top             =   2400
         Width           =   975
         _Version        =   65536
         _ExtentX        =   1720
         _ExtentY        =   873
         _StockProps     =   78
         Caption         =   "New"
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "MS Sans Serif"
            charset         =   0
            weight          =   700
            size            =   9.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
      End
      Begin VB.Line Line5 
         X1              =   240
         X2              =   3240
         Y1              =   2040
         Y2              =   2040
      End
      Begin VB.Line Line4 
         X1              =   240
         X2              =   3240
         Y1              =   1080
         Y2              =   1080
      End
      Begin VB.Line Line3 
         X1              =   2280
         X2              =   2280
         Y1              =   240
         Y2              =   2880
      End
      Begin VB.Line Line2 
         X1              =   1200
         X2              =   1200
         Y1              =   240
         Y2              =   2880
      End
      Begin VB.Label lblPlayerOWins 
         Alignment       =   2  'Center
         BeginProperty Font 
            name            =   "MS Sans Serif"
            charset         =   0
            weight          =   700
            size            =   9.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   4800
         TabIndex        =   18
         Top             =   1680
         Width           =   975
      End
      Begin VB.Label lblPlayerXWins 
         Alignment       =   2  'Center
         BeginProperty Font 
            name            =   "MS Sans Serif"
            charset         =   0
            weight          =   700
            size            =   9.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   3720
         TabIndex        =   17
         Top             =   1680
         Width           =   975
      End
      Begin VB.Label lblOWinsColumn 
         Alignment       =   2  'Center
         Caption         =   "O Wins"
         BeginProperty Font 
            name            =   "MS Sans Serif"
            charset         =   0
            weight          =   700
            size            =   9.75
            underline       =   -1  'True
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   4800
         TabIndex        =   16
         Top             =   1320
         Width           =   1095
      End
      Begin VB.Label lblXWinsColumn 
         Alignment       =   2  'Center
         Caption         =   "X Wins"
         BeginProperty Font 
            name            =   "MS Sans Serif"
            charset         =   0
            weight          =   700
            size            =   9.75
            underline       =   -1  'True
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   3720
         TabIndex        =   15
         Top             =   1320
         Width           =   975
      End
      Begin VB.Line Line1 
         X1              =   3480
         X2              =   3480
         Y1              =   240
         Y2              =   2880
      End
      Begin Threed.SSCommand btnResumeGame 
         Height          =   495
         Left            =   3720
         TabIndex        =   11
         Top             =   2040
         Visible         =   0   'False
         Width           =   975
         _Version        =   65536
         _ExtentX        =   1720
         _ExtentY        =   873
         _StockProps     =   78
         Caption         =   "Resume"
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "MS Sans Serif"
            charset         =   0
            weight          =   700
            size            =   9.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Enabled         =   0   'False
      End
      Begin Threed.SSCommand btnEndGame 
         Height          =   495
         Left            =   4800
         TabIndex        =   10
         Top             =   2400
         Width           =   1095
         _Version        =   65536
         _ExtentX        =   1931
         _ExtentY        =   873
         _StockProps     =   78
         Caption         =   "Exit"
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "MS Sans Serif"
            charset         =   0
            weight          =   700
            size            =   9.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
      End
      Begin VB.Label lblCurrentPlayersTurn 
         Alignment       =   2  'Center
         Caption         =   "Current Player:"
         BeginProperty Font 
            name            =   "MS Sans Serif"
            charset         =   0
            weight          =   700
            size            =   9.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   3720
         TabIndex        =   13
         Top             =   240
         Width           =   2175
      End
      Begin Threed.SSCommand btn9 
         Height          =   735
         Left            =   2400
         TabIndex        =   8
         Top             =   2160
         Width           =   855
         _Version        =   65536
         _ExtentX        =   1508
         _ExtentY        =   1296
         _StockProps     =   78
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "Times New Roman"
            charset         =   0
            weight          =   400
            size            =   15.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Font3D          =   4
      End
      Begin Threed.SSCommand btn8 
         Height          =   735
         Left            =   1320
         TabIndex        =   7
         Top             =   2160
         Width           =   855
         _Version        =   65536
         _ExtentX        =   1508
         _ExtentY        =   1296
         _StockProps     =   78
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "Times New Roman"
            charset         =   0
            weight          =   400
            size            =   15.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Font3D          =   4
      End
      Begin Threed.SSCommand btn7 
         Height          =   735
         Left            =   240
         TabIndex        =   6
         Top             =   2160
         Width           =   855
         _Version        =   65536
         _ExtentX        =   1508
         _ExtentY        =   1296
         _StockProps     =   78
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "Times New Roman"
            charset         =   0
            weight          =   400
            size            =   15.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Font3D          =   4
      End
      Begin Threed.SSCommand btn6 
         Height          =   735
         Left            =   2400
         TabIndex        =   5
         Top             =   1200
         Width           =   855
         _Version        =   65536
         _ExtentX        =   1508
         _ExtentY        =   1296
         _StockProps     =   78
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "Times New Roman"
            charset         =   0
            weight          =   400
            size            =   15.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Font3D          =   4
      End
      Begin Threed.SSCommand btn5 
         Height          =   735
         Left            =   1320
         TabIndex        =   4
         Top             =   1200
         Width           =   855
         _Version        =   65536
         _ExtentX        =   1508
         _ExtentY        =   1296
         _StockProps     =   78
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "Times New Roman"
            charset         =   0
            weight          =   400
            size            =   15.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Font3D          =   4
      End
      Begin Threed.SSCommand btn4 
         Height          =   735
         Left            =   240
         TabIndex        =   3
         Top             =   1200
         Width           =   855
         _Version        =   65536
         _ExtentX        =   1508
         _ExtentY        =   1296
         _StockProps     =   78
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "Times New Roman"
            charset         =   0
            weight          =   400
            size            =   15.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Font3D          =   4
      End
      Begin Threed.SSCommand btn3 
         Height          =   735
         Left            =   2400
         TabIndex        =   2
         Top             =   240
         Width           =   855
         _Version        =   65536
         _ExtentX        =   1508
         _ExtentY        =   1296
         _StockProps     =   78
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "Times New Roman"
            charset         =   0
            weight          =   400
            size            =   15.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Font3D          =   4
      End
      Begin Threed.SSCommand btn2 
         Height          =   735
         Left            =   1320
         TabIndex        =   1
         Top             =   240
         Width           =   855
         _Version        =   65536
         _ExtentX        =   1508
         _ExtentY        =   1296
         _StockProps     =   78
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "Times New Roman"
            charset         =   0
            weight          =   400
            size            =   15.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Font3D          =   4
      End
      Begin Threed.SSCommand btn1 
         Height          =   735
         Left            =   240
         TabIndex        =   0
         Top             =   240
         Width           =   855
         _Version        =   65536
         _ExtentX        =   1508
         _ExtentY        =   1296
         _StockProps     =   78
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            name            =   "Times New Roman"
            charset         =   0
            weight          =   400
            size            =   15.75
            underline       =   0   'False
            italic          =   0   'False
            strikethrough   =   0   'False
         EndProperty
         Font3D          =   4
      End
   End
   Begin VB.Menu mnuFile 
      Caption         =   "&File"
      Begin VB.Menu mnuNew 
         Caption         =   "&New"
      End
      Begin VB.Menu mnuResumeGame 
         Caption         =   "R&esume"
         Enabled         =   0   'False
      End
      Begin VB.Menu mnuFileSeparator1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuExit 
         Caption         =   "E&xit"
      End
   End
   Begin VB.Menu mnuOptions 
      Caption         =   "&Options"
      Enabled         =   0   'False
      Visible         =   0   'False
      Begin VB.Menu mnuCompDifficulty 
         Caption         =   "Computer &Difficulty"
         Begin VB.Menu mnuCompEasy 
            Caption         =   "&Easy"
            Checked         =   -1  'True
         End
         Begin VB.Menu mnuCompHard 
            Caption         =   "&Hard"
         End
      End
   End
   Begin VB.Menu mnuHelp 
      Caption         =   "&Help"
      Begin VB.Menu mnuAbout 
         Caption         =   "&About"
      End
   End
End
Attribute VB_Name = "MainForm"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
Option Explicit

Public CurrentPlayer As String              ' to determine player turns
Public PlayerXWins As Integer               ' for scoring X wins
Public PlayerOWins As Integer               ' for scoring O wins
Public IsPlayerOComputer As Boolean         ' turn on computer AI play
Public ComputerDifficulty As Integer        ' set computer AI difficulty setting
Public PlayerXMoveList As New Collection

Private Sub btnResumeGame_Click()
    ResumeGame
End Sub

Function CheckForStalemate() As Boolean
    If btn1.Enabled = False And _
      btn2.Enabled = False And _
      btn3.Enabled = False And _
      btn4.Enabled = False And _
      btn5.Enabled = False And _
      btn6.Enabled = False And _
      btn7.Enabled = False And _
      btn8.Enabled = False And _
      btn9.Enabled = False Then
        MsgBox "Stalemate", vbOKOnly + vbExclamation, "Tic Tac Toe"
        Dim response As Integer
        response = MsgBox("Play again?", vbYesNo + vbQuestion, "Tic Tac Toe")
        If response = vbYes Then
            Reset
        End If
        CheckForStalemate = True
    Else
        CheckForStalemate = False
    End If
End Function

Function CheckForWinner() As Boolean
    ' Compare strings across
    If btn1.Caption <> "" And StrComp(btn1.Caption, btn2.Caption) = 0 And StrComp(btn1.Caption, btn3.Caption) = 0 Then
        CheckForWinner = True
    ElseIf btn4.Caption <> "" And StrComp(btn4.Caption, btn5.Caption) = 0 And StrComp(btn4.Caption, btn6.Caption) = 0 Then
        CheckForWinner = True
    ElseIf btn7.Caption <> "" And StrComp(btn7.Caption, btn8.Caption) = 0 And StrComp(btn7.Caption, btn9.Caption) = 0 Then
        CheckForWinner = True
    ' Compare strings down
    ElseIf btn1.Caption <> "" And StrComp(btn1.Caption, btn4.Caption) = 0 And StrComp(btn1.Caption, btn7.Caption) = 0 Then
        CheckForWinner = True
    ElseIf btn2.Caption <> "" And StrComp(btn2.Caption, btn5.Caption) = 0 And StrComp(btn2.Caption, btn8.Caption) = 0 Then
        CheckForWinner = True
    ElseIf btn3.Caption <> "" And StrComp(btn3.Caption, btn6.Caption) = 0 And StrComp(btn3.Caption, btn9.Caption) = 0 Then
        CheckForWinner = True
    ' Check diagonal
    ElseIf btn1.Caption <> "" And StrComp(btn1.Caption, btn5.Caption) = 0 And StrComp(btn1.Caption, btn9.Caption) = 0 Then
        CheckForWinner = True
    ElseIf btn3.Caption <> "" And StrComp(btn3.Caption, btn5.Caption) = 0 And StrComp(btn3.Caption, btn7.Caption) = 0 Then
        CheckForWinner = True
    Else
        CheckForWinner = False
    End If
End Function


Sub DisableAll()
    btn1.Enabled = False
    btn2.Enabled = False
    btn3.Enabled = False
    btn4.Enabled = False
    btn5.Enabled = False
    btn6.Enabled = False
    btn7.Enabled = False
    btn8.Enabled = False
    btn9.Enabled = False
    mnuResumeGame.Enabled = True
    btnResumeGame.Enabled = True
End Sub


Sub ExitGame()
    Dim response As Integer
    response = MsgBox("Are you sure you want to quit?", vbYesNo + vbQuestion + vbDefaultButton2, "Quit Tic Tac Toe")
    If response = vbYes Then
        Unload Me
    End If
End Sub



Function GetRandomNumber() As Integer
    ' Generate random value between 1 and 9.
    GetRandomNumber = Int((9 * Rnd) + 1)
End Function



Function PlayerWon(Player As String)
    MsgBox "Player " & Player & " wins!", vbOKOnly, "Game over"
    Dim response As Integer
    response = MsgBox("Play again?", vbYesNo + vbQuestion, "Tic Tac Toe")
    If response = vbYes Then
        Reset
        Exit Function
    End If
    DisableAll
End Function


Sub ProcessComputerTurn()
    Dim Move As Integer
    Dim MoveSet As Integer
    ' Easy computer opponent with random moves
    If ComputerDifficulty = 1 Then GoTo RandomMove
    
    ' Hard computer opponent
    If ComputerDifficulty = 3 Then
        ' Try 5 on first move, else randomize
        If PlayerXMoveList.Count = 1 Then
            If TryMove(5) = False Then
                GoTo RandomMove
            End If
        End If
        
        ' calculate next moves
        If PlayerXMoveList.Count = 2 Then
            MoveSet = PlayerXMoveList(1) * PlayerXMoveList(2)
        ElseIf PlayerXMoveList.Count = 3 Then
            MoveSet = PlayerXMoveList(1) * PlayerXMoveList(2) * PlayerXMoveList(3)
        ElseIf PlayerXMoveList.Count = 4 Then
            MoveSet = PlayerXMoveList(2) * PlayerXMoveList(3) * PlayerXMoveList(4)
        ElseIf PlayerXMoveList.Count = 5 Then
            MoveSet = PlayerXMoveList(3) * PlayerXMoveList(4) * PlayerXMoveList(5)
        End If
        If PlayerXMoveList.Count > 1 Then
            Debug.Print "Move set calculated to " & MoveSet
        End If
        
        If PlayerXMoveList.Count = 2 Then
            ' Now try to block move
            If MoveSet = 6 Or MoveSet = 28 Or MoveSet = 45 Then
                ' If move doesn't work, then randomize play
                Debug.Print "Trying tile 1"
                If TryMove(1) = False Then GoTo RandomMove
            ElseIf MoveSet = 3 Or MoveSet = 40 Then
                Debug.Print "Trying tile 2"
                If TryMove(2) = False Then GoTo RandomMove
            ElseIf MoveSet = 2 Or MoveSet = 35 Or MoveSet = 54 Then
                Debug.Print "Trying tile 3"
                If TryMove(3) = False Then GoTo RandomMove
            ElseIf MoveSet = 7 Or MoveSet = 30 Then
                Debug.Print "Trying tile 4"
                If TryMove(4) = False Then GoTo RandomMove
            ElseIf MoveSet = 9 Or MoveSet = 16 Or MoveSet = 21 Or MoveSet = 24 Then
                Debug.Print "Trying tile 5"
                If TryMove(5) = False Then GoTo RandomMove
            ElseIf MoveSet = 20 Or MoveSet = 27 Then
                Debug.Print "Trying tile 6"
                If TryMove(6) = False Then GoTo RandomMove
            ElseIf MoveSet = 4 Or MoveSet = 15 Or MoveSet = 72 Then
                Debug.Print "Trying tile 7"
                If TryMove(7) = False Then GoTo RandomMove
            ElseIf MoveSet = 10 Or MoveSet = 63 Then
                Debug.Print "Trying tile 8"
                If TryMove(8) = False Then GoTo RandomMove
            ElseIf MoveSet = 5 Or MoveSet = 18 Or MoveSet = 56 Then
                Debug.Print "Trying tile 9"
                If TryMove(9) = False Then GoTo RandomMove
            Else: GoTo RandomMove
            End If
        ElseIf PlayerXMoveList.Count > 2 Then
            ' first see if we have a winning move
            ' there are 28 possible combinations to check for
            ' start with across the top
            If btn1.Caption = CurrentPlayer And btn2.Caption = CurrentPlayer And btn3.Caption = "" Then
                TryMove (3)
            ElseIf btn1.Caption = CurrentPlayer And btn3.Caption = CurrentPlayer And btn2.Caption = "" Then
                TryMove (2)
            ElseIf btn2.Caption = CurrentPlayer And btn3.Caption = CurrentPlayer And btn1.Caption = "" Then
                TryMove (1)
            ' then check middle
            ElseIf btn4.Caption = CurrentPlayer And btn5.Caption = CurrentPlayer And btn6.Caption = "" Then
                TryMove (6)
            ElseIf btn4.Caption = CurrentPlayer And btn6.Caption = CurrentPlayer And btn4.Caption = "" Then
                TryMove (5)
            ElseIf btn6.Caption = CurrentPlayer And btn5.Caption = CurrentPlayer And btn4.Caption = "" Then
                TryMove (4)
            ' now check bottom
            ElseIf btn7.Caption = CurrentPlayer And btn8.Caption = CurrentPlayer And btn9.Caption = "" Then
                TryMove (9)
            ElseIf btn7.Caption = CurrentPlayer And btn9.Caption = CurrentPlayer And btn8.Caption = "" Then
                TryMove (8)
            ElseIf btn8.Caption = CurrentPlayer And btn9.Caption = CurrentPlayer And btn7.Caption = "" Then
                TryMove (7)
            ' now check left column
            ElseIf btn1.Caption = CurrentPlayer And btn4.Caption = CurrentPlayer And btn7.Caption = "" Then
                TryMove (7)
            ElseIf btn1.Caption = CurrentPlayer And btn7.Caption = CurrentPlayer And btn4.Caption = "" Then
                TryMove (4)
            ElseIf btn4.Caption = CurrentPlayer And btn7.Caption = CurrentPlayer And btn1.Caption = "" Then
                TryMove (1)
            ' check middle column
            ElseIf btn2.Caption = CurrentPlayer And btn5.Caption = CurrentPlayer And btn8.Caption = "" Then
                TryMove (8)
            ElseIf btn2.Caption = CurrentPlayer And btn8.Caption = CurrentPlayer And btn5.Caption = "" Then
                TryMove (5)
            ElseIf btn5.Caption = CurrentPlayer And btn8.Caption = CurrentPlayer And btn2.Caption = "" Then
                TryMove (2)
            ' check right column
            ElseIf btn3.Caption = CurrentPlayer And btn6.Caption = CurrentPlayer And btn9.Caption = "" Then
                TryMove (9)
            ElseIf btn3.Caption = CurrentPlayer And btn9.Caption = CurrentPlayer And btn6.Caption = "" Then
                TryMove (6)
            ElseIf btn6.Caption = CurrentPlayer And btn9.Caption = CurrentPlayer And btn3.Caption = "" Then
                TryMove (3)
            ' check 1-5-9 diagonal
            ElseIf btn1.Caption = CurrentPlayer And btn5.Caption = CurrentPlayer And btn9.Caption = "" Then
                TryMove (9)
            ElseIf btn1.Caption = CurrentPlayer And btn9.Caption = CurrentPlayer And btn5.Caption = "" Then
                TryMove (5)
            ElseIf btn5.Caption = CurrentPlayer And btn9.Caption = CurrentPlayer And btn1.Caption = "" Then
                TryMove (1)
            ' lastly check 3-5-7 diagonal
            ElseIf btn3.Caption = CurrentPlayer And btn5.Caption = CurrentPlayer And btn7.Caption = "" Then
                TryMove (7)
            ElseIf btn3.Caption = CurrentPlayer And btn7.Caption = CurrentPlayer And btn5.Caption = "" Then
                TryMove (5)
            ElseIf btn7.Caption = CurrentPlayer And btn5.Caption = CurrentPlayer And btn3.Caption = "" Then
                TryMove (3)
            End If
                
            ' try move after calculating last 3 moves
            If MoveSet = 15 Then
                Debug.Print "Move set prediction hit"
                ' 2, 5, 7 are possible wins
                If TryMove(7) = False Then
                    If TryMove(5) = False Then
                        If TryMove(2) = False Then
                            GoTo RandomMove
                        End If
                    End If
                End If
            ElseIf MoveSet = 21 Then
                Debug.Print "Move set prediction hit"
                ' 2, 4, 5 are possible wins
                If TryMove(5) = False Then
                    If TryMove(4) = False Then
                        If TryMove(2) = False Then
                            GoTo RandomMove
                        End If
                    End If
                End If
            ElseIf MoveSet = 27 Then
                Debug.Print "Move set prediction hit"
                ' 2, 5, 6 are possible wins
                If TryMove(5) = False Then
                        If TryMove(6) = False Then
                            If TryMove(2) = False Then
                                GoTo RandomMove
                            End If
                        End If
                End If
            ElseIf MoveSet = 135 Then
                Debug.Print "Move set prediction hit"
                ' 1, 6, 7 are possible wins
                If TryMove(7) = False Then
                        If TryMove(6) = False Then
                            If TryMove(1) = False Then
                                GoTo RandomMove
                            End If
                        End If
                End If
            ElseIf MoveSet = 189 Then
                Debug.Print "Move set prediction hit"
                ' 6, 7, 8 are possible wins
                If TryMove(8) = False Then
                        If TryMove(7) = False Then
                            If TryMove(6) = False Then
                                GoTo RandomMove
                            End If
                        End If
                End If
            ElseIf MoveSet = 315 Then
                Debug.Print "Move set prediction hit"
                ' 1, 3, 8 are possible wins
                If TryMove(8) = False Then
                        If TryMove(3) = False Then
                            If TryMove(1) = False Then
                                GoTo RandomMove
                            End If
                        End If
                End If
            ElseIf MoveSet = 48 Or MoveSet = 64 Or MoveSet = 96 Or MoveSet = 192 Then
                Debug.Print "Move set prediction hit"
                ' 5 is the only possible winning move
                If TryMove(5) = False Then GoTo RandomMove
            Else
                Debug.Print "Move set prediction miss"
                Debug.Print "Predictive analysis failed. Checking all probabilities"
                ' start with across the top
                If Not (btn1.Caption = CurrentPlayer) And Not (btn1.Caption = "") _
                    And Not (btn2.Caption = CurrentPlayer) And Not (btn2.Caption = "") _
                    And btn3.Caption = "" Then
                    TryMove (3)
                ElseIf Not (btn1.Caption = CurrentPlayer) And Not (btn1.Caption = "") _
                    And Not (btn3.Caption = CurrentPlayer) And Not (btn3.Caption = "") _
                    And btn2.Caption = "" Then
                    TryMove (2)
                ElseIf Not (btn2.Caption = CurrentPlayer) And Not (btn2.Caption = "") _
                    And Not (btn3.Caption = CurrentPlayer) And Not (btn3.Caption = "") _
                    And btn1.Caption = "" Then
                    TryMove (1)
                ' then check middle
                ElseIf Not (btn4.Caption = CurrentPlayer) And Not (btn4.Caption = "") _
                    And Not (btn5.Caption = CurrentPlayer) And Not (btn5.Caption = "") _
                    And btn6.Caption = "" Then
                    TryMove (6)
                ElseIf Not (btn4.Caption = CurrentPlayer) And Not (btn4.Caption = "") _
                    And Not (btn6.Caption = CurrentPlayer) And Not (btn6.Caption = "") _
                    And btn4.Caption = "" Then
                    TryMove (5)
                ElseIf Not (btn6.Caption = CurrentPlayer) And Not (btn6.Caption = "") _
                    And Not (btn5.Caption = CurrentPlayer) And Not (btn5.Caption = "") _
                    And btn4.Caption = "" Then
                    TryMove (4)
                ' now check bottom
                ElseIf Not (btn7.Caption = CurrentPlayer) And Not (btn7.Caption = "") _
                    And Not (btn8.Caption = CurrentPlayer) And Not (btn8.Caption = "") _
                    And btn9.Caption = "" Then
                    TryMove (9)
                ElseIf Not (btn7.Caption = CurrentPlayer) And Not (btn7.Caption = "") _
                    And Not (btn9.Caption = CurrentPlayer) And Not (btn9.Caption = "") _
                    And btn8.Caption = "" Then
                    TryMove (8)
                ElseIf Not (btn8.Caption = CurrentPlayer) And Not (btn8.Caption = "") _
                    And Not (btn9.Caption = CurrentPlayer) And Not (btn9.Caption = "") _
                    And btn7.Caption = "" Then
                    TryMove (7)
                ' now check left column
                ElseIf Not (btn1.Caption = CurrentPlayer) And Not (btn1.Caption = "") _
                    And Not (btn4.Caption = CurrentPlayer) And Not (btn4.Caption = "") _
                    And btn7.Caption = "" Then
                    TryMove (7)
                ElseIf Not (btn1.Caption = CurrentPlayer) And Not (btn1.Caption = "") _
                And Not (btn7.Caption = CurrentPlayer) And Not (btn7.Caption = "") _
                And btn4.Caption = "" Then
                    TryMove (4)
                ElseIf Not (btn4.Caption = CurrentPlayer) And Not (btn4.Caption = "") _
                    And Not (btn7.Caption = CurrentPlayer) And Not (btn7.Caption = "") _
                    And btn1.Caption = "" Then
                    TryMove (1)
                ' check middle column
                ElseIf Not (btn2.Caption = CurrentPlayer) And Not (btn2.Caption = "") _
                    And Not (btn5.Caption = CurrentPlayer) And Not (btn5.Caption = "") _
                    And btn8.Caption = "" Then
                    TryMove (8)
                ElseIf Not (btn2.Caption = CurrentPlayer) And Not (btn2.Caption = "") _
                    And Not (btn8.Caption = CurrentPlayer) And Not (btn8.Caption = "") _
                    And btn5.Caption = "" Then
                    TryMove (5)
                ElseIf Not (btn5.Caption = CurrentPlayer) And Not (btn5.Caption = "") _
                    And Not (btn8.Caption = CurrentPlayer) And Not (btn8.Caption = "") _
                    And btn2.Caption = "" Then
                    TryMove (2)
                ' check right column
                ElseIf Not (btn3.Caption = CurrentPlayer) And Not (btn3.Caption = "") _
                    And Not (btn6.Caption = CurrentPlayer) And Not (btn6.Caption = "") _
                    And btn9.Caption = "" Then
                    TryMove (9)
                ElseIf Not (btn3.Caption = CurrentPlayer) And Not (btn3.Caption = "") _
                    And Not (btn9.Caption = CurrentPlayer) And Not (btn9.Caption = "") _
                    And btn6.Caption = "" Then
                    TryMove (6)
                ElseIf Not (btn6.Caption = CurrentPlayer) And Not (btn6.Caption = "") _
                    And Not (btn9.Caption = CurrentPlayer) And Not (btn9.Caption = "") _
                    And btn3.Caption = "" Then
                    TryMove (3)
                ' check 1-5-9 diagonal
                ElseIf Not (btn1.Caption = CurrentPlayer) And Not (btn1.Caption = "") _
                    And Not (btn5.Caption = CurrentPlayer) And Not (btn5.Caption = "") _
                    And btn9.Caption = "" Then
                    TryMove (9)
                ElseIf Not (btn1.Caption = CurrentPlayer) And Not (btn1.Caption = "") _
                    And Not (btn9.Caption = CurrentPlayer) And Not (btn9.Caption = "") _
                    And btn5.Caption = "" Then
                    TryMove (5)
                ElseIf Not (btn5.Caption = CurrentPlayer) And Not (btn5.Caption = "") _
                    And Not (btn9.Caption = CurrentPlayer) And Not (btn9.Caption = "") _
                    And btn1.Caption = "" Then
                    TryMove (1)
                ' lastly check 3-5-7 diagonal
                ElseIf Not (btn3.Caption = CurrentPlayer) And Not (btn3.Caption = "") _
                    And Not (btn5.Caption = CurrentPlayer) And Not (btn5.Caption = "") _
                    And btn7.Caption = "" Then
                    TryMove (7)
                ElseIf Not (btn3.Caption = CurrentPlayer) And Not (btn3.Caption = "") _
                    And Not (btn7.Caption = CurrentPlayer) And Not (btn7.Caption = "") _
                    And btn5.Caption = "" Then
                    TryMove (5)
                ElseIf Not (btn7.Caption = CurrentPlayer) And Not (btn7.Caption = "") _
                    And Not (btn5.Caption = CurrentPlayer) And Not (btn5.Caption = "") _
                    And btn3.Caption = "" Then
                    TryMove (3)
                Else
                    Debug.Print "All probability analysis failed. Randomizing move..."
                    ' all analysis failed. randomize play
                    GoTo RandomMove
                End If
            End If
        End If
    End If
    GoTo Finish
    
RandomMove:
    Do
        Move = GetRandomNumber()
        Debug.Print "Got random number " & Move
        If TryMove(Move) Then
            Exit Do
        End If
        ' Keep application & OS responsive
        DoEvents
    Loop

Finish:
    ProcessPostTurn
End Sub



Sub ProcessPostTurn()
    ' Check if button selection wins the game
    If CheckForWinner() = True Then
        ' If winner was player X...
        If CurrentPlayer = "X" Then
            ' Add win to total
            PlayerXWins = PlayerXWins + 1
            ' Show on scoreboard
            lblPlayerXWins.Caption = Format(PlayerXWins, "#,###,##0")
        ' otherwise winner was player O...
        Else
            PlayerOWins = PlayerOWins + 1
            lblPlayerOWins.Caption = Format(PlayerOWins, "#,###,##0")
        End If
        PlayerWon (CurrentPlayer)
    ' ElseIf button selection wasn't a winner
    ' see if it resulted in stalemate
    ElseIf CheckForStalemate() = False Then
        ' switch to next player
        If CurrentPlayer = "X" Then
            CurrentPlayer = "O"
        Else
            CurrentPlayer = "X"
        End If
        ' update current player panel
        CurrentPlayerPanel.Caption = CurrentPlayer
        ' if player is O and is computer
        ' process turn
        If CurrentPlayer = "O" And IsPlayerOComputer Then
            ProcessComputerTurn
        End If
    End If
End Sub


Sub Reset()
    btn1.Caption = ""
    btn1.Enabled = True
    btn2.Caption = ""
    btn2.Enabled = True
    btn3.Caption = ""
    btn3.Enabled = True
    btn4.Caption = ""
    btn4.Enabled = True
    btn5.Caption = ""
    btn5.Enabled = True
    btn6.Caption = ""
    btn6.Enabled = True
    btn7.Caption = ""
    btn7.Enabled = True
    btn8.Caption = ""
    btn8.Enabled = True
    btn9.Caption = ""
    btn9.Enabled = True
    CurrentPlayer = "X"
    If PlayerXMoveList.Count <> 0 Then
        Dim i As Integer
        For i = PlayerXMoveList.Count To 1 Step -1
            PlayerXMoveList.Remove (i)
        Next
    End If
End Sub



Sub ResetGame()
    Dim response As Integer
    response = MsgBox("Are you sure you want to reset the game?", vbYesNo + vbQuestion + vbDefaultButton2, "Reset")
    If response = vbYes Then
        Reset
        btnResumeGame.Enabled = False
        mnuResumeGame.Enabled = False
    End If
End Sub


Sub ResumeGame()
    Dim response As Integer
    response = MsgBox("Are you sure you want to resume the game?", vbYesNo + vbQuestion + vbDefaultButton2, "Resume")
    If response = vbYes Then
        Reset
        btnResumeGame.Enabled = False
        mnuResumeGame.Enabled = False
    End If
End Sub


Sub StartNewGame()
    Dim response As Integer
    response = MsgBox("Is Player O a computer player?", vbYesNo, "Tic Tac Toe")
    If response = vbYes Then
        IsPlayerOComputer = True
        ComputerDifficulty = 3
        'If mnuCompEasy.Checked And Not mnuCompHard.Checked Then
        '    ComputerDifficulty = 1
        'ElseIf Not mnuCompEasy.Checked And mnuCompHard.Checked Then
        '    ComputerDifficulty = 3
        'End If
    Else
        IsPlayerOComputer = False
    End If
    CurrentPlayer = "X"
End Sub


Function TryMove(button As Integer) As Boolean
    If button = 1 And btn1.Enabled Then
        btn1.Caption = CurrentPlayer
        btn1.Enabled = False
        TryMove = True
    ElseIf button = 2 And btn2.Enabled Then
        btn2.Caption = CurrentPlayer
        btn2.Enabled = False
        TryMove = True
    ElseIf button = 3 And btn3.Enabled Then
        btn3.Caption = CurrentPlayer
        btn3.Enabled = False
        TryMove = True
    ElseIf button = 4 And btn4.Enabled Then
        btn4.Caption = CurrentPlayer
        btn4.Enabled = False
        TryMove = True
    ElseIf button = 5 And btn5.Enabled Then
        btn5.Caption = CurrentPlayer
        btn5.Enabled = False
        TryMove = True
    ElseIf button = 6 And btn6.Enabled Then
        btn6.Caption = CurrentPlayer
        btn6.Enabled = False
        TryMove = True
    ElseIf button = 7 And btn7.Enabled Then
        btn7.Caption = CurrentPlayer
        btn7.Enabled = False
        TryMove = True
    ElseIf button = 8 And btn8.Enabled Then
        btn8.Caption = CurrentPlayer
        btn8.Enabled = False
        TryMove = True
    ElseIf button = 9 And btn9.Enabled Then
        btn9.Caption = CurrentPlayer
        btn9.Enabled = False
        TryMove = True
    Else
        TryMove = False
    End If
End Function


Private Sub btn1_Click()
    ' user can't click unless enabled so we
    ' assume if the click action occurs, the
    ' button must be enabled
    Dim Move As Integer: Move = 1
    TryMove (Move)
    If CurrentPlayer = "X" Then
        PlayerXMoveList.Add (Move)
    End If
    ProcessPostTurn
End Sub

Private Sub btn2_Click()
    ' user can't click unless enabled so we
    ' assume if the click action occurs, the
    ' button must be enabled
    Dim Move As Integer: Move = 2
    TryMove (Move)
    If CurrentPlayer = "X" Then
        PlayerXMoveList.Add (Move)
    End If
    ProcessPostTurn
End Sub


Private Sub btn3_Click()
    ' user can't click unless enabled so we
    ' assume if the click action occurs, the
    ' button must be enabled
    Dim Move As Integer: Move = 3
    TryMove (Move)
    If CurrentPlayer = "X" Then
        PlayerXMoveList.Add (Move)
    End If
    ProcessPostTurn
End Sub


Private Sub btn4_Click()
    ' user can't click unless enabled so we
    ' assume if the click action occurs, the
    ' button must be enabled
    Dim Move As Integer: Move = 4
    TryMove (Move)
    If CurrentPlayer = "X" Then
        PlayerXMoveList.Add (Move)
    End If
    ProcessPostTurn
End Sub


Private Sub btn5_Click()
    ' user can't click unless enabled so we
    ' assume if the click action occurs, the
    ' button must be enabled
    Dim Move As Integer: Move = 5
    TryMove (Move)
    If CurrentPlayer = "X" Then
        PlayerXMoveList.Add (Move)
    End If
    ProcessPostTurn
End Sub


Private Sub btn6_Click()
    ' user can't click unless enabled so we
    ' assume if the click action occurs, the
    ' button must be enabled
    Dim Move As Integer: Move = 6
    TryMove (Move)
    If CurrentPlayer = "X" Then
        PlayerXMoveList.Add (Move)
    End If
    ProcessPostTurn
End Sub


Private Sub btn7_Click()
    ' user can't click unless enabled so we
    ' assume if the click action occurs, the
    ' button must be enabled
    Dim Move As Integer: Move = 7
    TryMove (Move)
    If CurrentPlayer = "X" Then
        PlayerXMoveList.Add (Move)
    End If
    ProcessPostTurn
End Sub


Private Sub btn8_Click()
    ' user can't click unless enabled so we
    ' assume if the click action occurs, the
    ' button must be enabled
    Dim Move As Integer: Move = 8
    TryMove (Move)
    If CurrentPlayer = "X" Then
        PlayerXMoveList.Add (Move)
    End If
    ProcessPostTurn
End Sub


Private Sub btn9_Click()
    ' user can't click unless enabled so we
    ' assume if the click action occurs, the
    ' button must be enabled
    Dim Move As Integer: Move = 9
    TryMove (Move)
    If CurrentPlayer = "X" Then
        PlayerXMoveList.Add (Move)
    End If
    ProcessPostTurn
End Sub


Private Sub btnEndGame_Click()
    ExitGame
End Sub

Private Sub btnResetGame_Click()
    ResetGame
End Sub


Private Sub btnStartNewGame_Click()
    Dim response As Integer
    response = MsgBox("Start a new game?", vbYesNo + vbQuestion, "Tic Tac Toe")
    If response = vbYes Then
        PlayerXWins = 0
        PlayerOWins = 0
        lblPlayerXWins.Caption = PlayerXWins
        lblPlayerOWins.Caption = PlayerOWins
        StartNewGame
        Reset
    End If
End Sub

Private Sub Form_Load()
    CurrentPlayer = "X"
    CurrentPlayerPanel.Caption = CurrentPlayer
    PlayerXWins = 0
    PlayerOWins = 0
    lblPlayerXWins = PlayerXWins
    lblPlayerOWins = PlayerOWins
    
    'StartNewGame
    DisableAll
End Sub


Private Sub mnuAbout_Click()
    AboutBox.Show 1
End Sub

Private Sub mnuCompEasy_Click()
    If PlayerXWins = 0 And PlayerOWins = 0 Then
        If mnuCompHard.Checked = True Then
            mnuCompHard.Checked = False
            mnuCompEasy.Checked = True
            ComputerDifficulty = 1
        End If
    Else
        mnuCompEasy.Checked = False
        mnuCompHard.Checked = True
        MsgBox "Cannot change computer difficulty mid-game." & vbCrLf & "Please start a new game then change difficulty settings.", vbOKOnly + vbExclamation, "Tic Tac Toe"
    End If
End Sub

Private Sub mnuCompHard_Click()
    If PlayerXWins = 0 And PlayerOWins = 0 Then
        If mnuCompEasy.Checked = True Then
            mnuCompEasy.Checked = False
            mnuCompHard.Checked = True
            ComputerDifficulty = 3
        End If
    Else
        mnuCompEasy.Checked = True
        mnuCompHard.Checked = False
        MsgBox "Cannot change computer difficulty mid-game." & vbCrLf & "Please start a new game then change difficulty settings.", vbOKOnly + vbExclamation, "Tic Tac Toe"
    End If
End Sub


Private Sub mnuExit_Click()
    ExitGame
End Sub


Private Sub mnuNew_Click()
    Dim response As Integer
    response = MsgBox("Start a new game?", vbYesNo + vbQuestion, "Tic Tac Toe")
    If response = vbYes Then
        PlayerXWins = 0
        PlayerOWins = 0
        lblPlayerXWins.Caption = PlayerXWins
        lblPlayerOWins.Caption = PlayerOWins
        StartNewGame
        Reset
    End If
End Sub

Private Sub mnuResetGame_Click()
    ResetGame
End Sub

Private Sub mnuResumeGame_Click()
    ResumeGame
End Sub


