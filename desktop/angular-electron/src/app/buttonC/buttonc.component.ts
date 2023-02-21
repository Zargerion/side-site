import {Component, OnInit} from '@angular/core';

@Component({
    selector:'button-c',
    templateUrl: './buttonc.component.html'
})
export class ButtonCComponent implements OnInit{
    ngOnInit(): void { }

    showAlert() {
        alert("Alert!");
      }
}