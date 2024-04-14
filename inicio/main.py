import flet as ft

def main(page: ft.Page):

    page.add(
        ft.Row(
            [
                ft.IconButton(ft.icons.REMOVE),
                ft.TextField(value="0", text_align=ft.TextAlign.CENTER, width= 100),
                ft.IconButton(ft.icons.ADD),
            ]
        )
    )
ft.app(main)