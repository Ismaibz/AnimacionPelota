object MainForm: TMainForm
  Left = 238
  Top = 160
  Width = 696
  Height = 480
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClick = FormClick
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 32
    Top = 40
    object Salir1: TMenuItem
      Caption = 'Salir'
    end
    object NuevaPelota1: TMenuItem
      Caption = 'Nueva Pelota'
      OnClick = NuevaPelota1Click
    end
  end
end
