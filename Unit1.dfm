object Form1: TForm1
  Left = 650
  Top = 208
  Caption = 'Search Spam-Program'
  ClientHeight = 416
  ClientWidth = 939
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 112
    Top = 8
    Width = 153
    Height = 25
    Caption = 'Search'
    TabOrder = 0
    OnClick = Button1Click
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 39
    Width = 365
    Height = 338
    DataSource = DataSource1
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Width = 25
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Name'
        Title.Caption = '  '#1055#1086#1083#1085#1086#1077' '#1080#1084#1103
        Width = 187
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Name_2'
        Title.Caption = '  '#1050#1083#1102#1095#1077#1074#1086#1077' '#1089#1083#1086#1074#1086
        Width = 117
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 56
    Top = 383
    Width = 240
    Height = 25
    DataSource = DataSource1
    TabOrder = 2
  end
  object Button2: TButton
    Left = 301
    Top = 383
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 379
    Top = 39
    Width = 552
    Height = 369
    Lines.Strings = (
      'Memo1')
    TabOrder = 4
  end
  object Button3: TButton
    Left = 271
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 5
    OnClick = Button3Click
  end
  object ADOTable1: TADOTable
    Active = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Base.mdb;Persist Se' +
      'curity Info=False'
    CursorType = ctStatic
    TableName = 'Paramet_ers'
    Left = 208
    Top = 312
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 160
    Top = 312
  end
end
