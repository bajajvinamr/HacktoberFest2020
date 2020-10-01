package com.example.simplenoteapplication;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class NoteAdapter extends BaseAdapter {
    private ArrayList<NoteInfo> _noteList;
    private LayoutInflater _layoutInflater;
    private Context _context;
    ArrayList<NoteInfo> arrNoteTemp ;


    public NoteAdapter(Context aContext, ArrayList<NoteInfo> note_details) {
        this._context = aContext;
        this._noteList = new ArrayList<NoteInfo>(note_details);
        _layoutInflater = LayoutInflater.from(aContext);
        arrNoteTemp = new ArrayList<NoteInfo>(_noteList);
    }

    static class ViewHolder {
        TextView editTitleView;
        TextView editTagView;
        TextView editContentView;
        TextView dateView;
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public int getCount() {
        return _noteList.size();
    }

    @Override
    public Object getItem(int index) {
        return _noteList.get(index);
    }

    @Override
    public View getView(int index, View convertView, ViewGroup viewGroup) {
        ViewHolder viewHolder;

        if (convertView == null) {
            convertView = _layoutInflater.inflate(R.layout.item_note, null);
            viewHolder = new ViewHolder();
            viewHolder.editTitleView = (TextView) convertView.findViewById(R.id.textTitle);
            viewHolder.editTagView= (TextView) convertView.findViewById(R.id.textTag);
            viewHolder.editContentView = (TextView) convertView.findViewById(R.id.textContent);
            viewHolder.dateView = (TextView) convertView.findViewById(R.id.noteDate);
            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder) convertView.getTag();
        }

        NoteInfo noteInfo = this._noteList.get(index);
        viewHolder.editTitleView.setText(noteInfo.get_Title());
        viewHolder.editTagView.setText((noteInfo.get_Tag()));
        viewHolder.editContentView.setText(noteInfo.get_Content());
        viewHolder.dateView.setText(noteInfo.get_Date().toString());
        return convertView;
    }

    public void filter(String charText)
    {
        charText = charText.toLowerCase();
        _noteList.clear();
        if (charText.length() == 0){
            _noteList.addAll(arrNoteTemp);
        }
        else{
            for(NoteInfo notiinfo : arrNoteTemp){
                if(notiinfo.get_Title().toLowerCase().contains(charText))
                {
                    _noteList.add(notiinfo);
                    super.notifyDataSetChanged();
                }
            }
        }
        super.notifyDataSetChanged();
    }
}
