var data= [];
var width= 620;
var height= 800;
var pdfName;
var fileName= '';

const createPDF= document.getElementById('create-pdf');

encodeImageFileAsURL= (element)=>{
    document.getElementById('input-page').style.display= 'none';
    document.getElementById('pdf-page').style.display= 'inline-block';

    const length= element.files.length;
    for(var i=0;i<length;i++){
        let file= element.files[i];
        let pdfname= element.files[0];
        let reader= new FileReader();
        reader.readAsDataURL(file);

        let obj= {
            list: reader,
            fileName: file.name,
            time: new Date().toString() + i
        }

        reader.onloadend= ()=>{
            data= [...data,obj];
            pdfName= pdfname.name
        }
    }

    setTimeout(convertToPDF,1000);
    document.getElementById('upload-msg').value= null;
    document.getElementById('upload-file').value= null;
    setTimeout(saveAsPDF,1000);
}


saveAsPDF= ()=>{
    document.getElementById('upload-msg').style.display= 'none';
    document.getElementById('convertBtn').style.display= 'inline-block';
}


//delete item from pdf page
handleDelete= (e)=>{
    data= data.filter((item)=>item.time!==e.currentTarget.id);
    if(data.length==0){
        location.reload();
    }
    else{
        convertToPDF();
    }
}


//initiate file downloading
embedImages= async ()=>{
    const pdfDoc= await PDFLib.PDFDocument.create();
    for(var i=0;i<data.length;i++){
        const jpgUrl= data[i].list.result;
        const jpgImageBytes= await fetch(jpgUrl).then((res) => res.arrayBuffer());

        const jpgImage = await pdfDoc.embedJpg(jpgImageBytes);

        //Add a blank page to the document
        const page= pdfDoc.addPage();

        //set page size
        page.setSize(width,height);
        page.drawImage(jpgImage, {
            x: 20,
            y: 50,
            width: page.getWidth()-40,
            height: page.getHeight()-100,
        })
    }

    //save the padf pages
    const pdfBytes= await pdfDoc.save();

    //download pdf file 
    download(pdfBytes, pdfName.slice(0,-4), "application/pdf");

    //back to home page after downloading file
    setTimeout(backToHomepage,1000);
}

//display pdf images
function convertToPDF(){
    createPDF.innerHTML= '';
    data.map((item,i)=>{
        const fileItem= document.createElement('div');
        fileItem.setAttribute('class','file-item');

        const modify= document.createElement('div');
        modify.setAttribute('class','modify');

        const button2= document.createElement('button');
        button2.setAttribute('class','delete-btn');
        button2.setAttribute('id',item.time);
        const remove= document.createElement('i');
        remove.setAttribute('class','fa fa-trash');
        button2.appendChild(remove);
        button2.addEventListener('click',(e)=>{
            handleDelete(e);
        });

        modify.appendChild(button2);

        fileItem.appendChild(modify);

        const imgContainer= document.createElement('div');
        imgContainer.setAttribute('class','img-container');
        const img= document.createElement('img');
        img.setAttribute('id','img');
        img.src= item.list.result;
        imgContainer.appendChild(img);
        fileItem.appendChild(imgContainer);

        const imgName= document
        .createElement('p');
        imgName.setAttribute('id','img-name');
        imgName.innerHTML= item.fileName;
        fileItem.appendChild(imgName);

        //fileItem is the child of createPDF
        createPDF.appendChild(fileItem);

    });

    const addMoreFile= document.createElement('div');
    addMoreFile.setAttribute('class','add-more-file');

    const addFile= document.createElement('div');
    addFile.setAttribute('class','inp-cont');

    const input= document.createElement('input');
    input.setAttribute('id','inp');
    input.type= 'file';
    input.multiple= 'true';
    input.onchange= function(){
        encodeImageFileAsURL(this);
    }

    const p= document.createElement('p');
    const i= document.createElement('i');
    i.setAttribute('class','fa fa-plus');

    p.appendChild(i);

    const label= document.createElement('label');
    label.htmlFor= 'inp';
    label.innerHTML= 'Add Files';

    addFile.appendChild(p);
    addFile.appendChild(label);
    addFile.appendChild(input);
    
    //addFile is the child of addMoreFile
    addMoreFile.appendChild(addFile);

    //addMoreFile is the child of createPDF
    createPDF.appendChild(addMoreFile);
}

//back to home 
function backToHomepage(){
    location.reload();
}
